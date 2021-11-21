# dtts

`dtts` provides time-series functionality based on `nanotime` and `data.table`.

## Motivation

By using [`nanotime`](https://CRAN.R-project.org/package=nanotime) we
get time-series with nanosecond resolution and by basing them on
[`data.table`](https://CRAN.R-project.org/package=data.table) we can
leverage the conciseness, high performance, and memory efficiency.

These time-series are simply a `data.table` with a first column of
type `nanotime` and a key on it. This means all the standard
`data.table` functions can be used, and this package consolidates this
functionality.

Specifically, `dtts` proposes alignment functions that are
particularly versatile and allow to work across time-zones.

## Usage

### Creating a `data.table`-based time-series with a `nanotime` index

Three operations are necessary to create a `data.table`-based
time-series for use with the functions defined in this package:
1. Create the time index, i.e. a vector of `nanotime`
2. Create a `data.table` with the first column being the time index 
3. Specify the first column as a key

For instance, this code creates a time-series of 10 rows spaced every
hour with a data column `V1` containing random data:

~~~ R
library(data.table)
t1 <- seq(as.nanotime(Sys.time()), by=as.nanoduration("01:00:00"), length.out=10)
dt1 <- data.table(index=t1, V1=runif(10))
setkey(dt1, index)
~~~

Which produces:

~~~
                               index        V1
 1: 2021-11-21T06:23:12.404650+00:00 0.7206800
 2: 2021-11-21T07:23:12.404650+00:00 0.9677868
 3: 2021-11-21T08:23:12.404650+00:00 0.6211587
 4: 2021-11-21T09:23:12.404650+00:00 0.7669201
 5: 2021-11-21T10:23:12.404650+00:00 0.6426368
 6: 2021-11-21T11:23:12.404650+00:00 0.4026811
 7: 2021-11-21T12:23:12.404650+00:00 0.2512213
 8: 2021-11-21T13:23:12.404650+00:00 0.3476128
 9: 2021-11-21T14:23:12.404650+00:00 0.9663271
10: 2021-11-21T15:23:12.404650+00:00 0.4744729
~~~

### Alignment functions

Alignment is the process of matching one time series to another. All
alignment functions in this package work in a similar way. For each
point in the vector `y` onto which `x` is aligned, a pair or arguments
named `start` and `end` define an interval around it. As an example
let's take `start` equal to -1 hour and `end` equal to 0 hour. This
means that a `y` of 2021-11-20 11:00:00 defines an interval from
2021-11-20 10:00:00 to 2021-11-20 11:00:00. The alignment process will
then use that interval to pick points in order to compute one or more
statistics on that interval for the corresponding point in `y`.

In addition to the arguments `start` and `end`, two other arguments,
booleans named `sopen` and `eopen` define if the start and end,
respectively, of the interval are open or not.

Finally, note that when the interval is specified with a `nanoperiod`
type, the argument `tz` is necessary in order to give meaning to the
interval. With `nanoperiod`, alignments are time-zone aware and
correct across daylight saving time.


<img src="./inst/images/align_closest.svg">


#### `align.idx`

This function takes two vectors of type `nanotime`. It aligns the
first one onto the second one and returns the indices of the first
vector that align with the second vector. There is no choice of
aggregation function here as this function works uniquely on
`nanotime` vectors and so there are no `data.table` columns on which
to operate, so the behavior here is to take the point in `x` that
falls in the interval and that is closest to the point of alignment in
`y`. The index of the point that falls in that interval is returned at
the position of the vector `y`. If no point exists in that interval
`NaN` is returned.


~~~ R
library(dtts)

t1 <- seq(as.nanotime("1970-01-01T00:00:00+00:00"), by=as.nanoduration("00:00:01"), length.out=100)
t2 <- seq(as.nanotime("1970-01-01T00:00:10+00:00"), by=as.nanoduration("00:00:10"), length.out=10)

align.idx(t1, t2, start=as.nanoduration("-00:00:10"))
~~~

Which produces:

~~~
 [1]  10  20  30  40  50  60  70  80  90 100
~~~

#### `align`

This function takes a `data.table` and aligns is onto `y`, a vector of
`nanotime`. Like `align.idx`, it uses the arguments `start`, `end`,
`sopen` and `eopen` to define the intervals around the points in `y`. 

Instead of the result being an index, it is this time a new
`data.table` time-series with the first `nanotime` column being the
vector `y`, and the rows of this time-series are taken from the
`data.table` `x`. If no function is specified (i.e. `func` is `NULL`),
the function returns the row of the point in `x` that is in the
interval and that is closest to the point in `y` on which the
alignment is made. If `func` is defined, it receives for each point in
`y` all the rows in `x` that are in the defined interval. So `func`
must be a statistic that returns one row, but any number of
columns. Common examples are means (e.g. using `colMeans`), counts,
etc.


In the following example a time-series `dt1` is created with a data
column `V1` which has the integer index as value and it is aligned
onto a `nanotime` vector `t2`

~~~ R
library(dtts)

t1 <- seq(as.nanotime("1970-01-01T00:00:00+00:00"), by=as.nanoduration("00:00:01"), length.out=100)
dt1 <- data.table(index=t1, V1=0:99)
setkey(dt1, index)

t2 <- seq(as.nanotime("1970-01-01T00:00:10+00:00"), by=as.nanoduration("00:00:10"), length.out=10)

align(dt1, t2, start=as.nanoduration("-00:00:10"), func=colMeans)
~~~

Which produces:

~~~
                        index   V1
 1: 1970-01-01T00:00:10+00:00  4.5
 2: 1970-01-01T00:00:20+00:00 14.5
 3: 1970-01-01T00:00:30+00:00 24.5
 4: 1970-01-01T00:00:40+00:00 34.5
 5: 1970-01-01T00:00:50+00:00 44.5
 6: 1970-01-01T00:01:00+00:00 54.5
 7: 1970-01-01T00:01:10+00:00 64.5
 8: 1970-01-01T00:01:20+00:00 74.5
 9: 1970-01-01T00:01:30+00:00 84.5
10: 1970-01-01T00:01:40+00:00 94.5
~~~

#### `grid.align`

This function adds one more dimension to the function `align` in the
sense that instead of taking a vector `y`, it constructs it as a grid
that has as interval the value supplied in the argument `by`. The
interval is controllable (with arguments `ival_start`, `ival_end`,
`ival_sopen`, `ival_eopen`) but it is likely that in most cases the
default will be used which is the grid interval. As for `align`, the
caller can specify `func`. Finally, note that `by` can be either a
`nanoduration` or a `nanoperiod`. In the latter case, as for the other
functions, the argument `tz` must be supplied so that the `nanoperiod`
interval can be anchored in a specific timezone.

The following example is the same as for the `align` function, but
shows how the vector `t2` does not need to be supplied as it is
instead constructed by `grid.align`:

~~~ R
library(dtts)

t1 <- seq(as.nanotime("1970-01-01T00:00:00+00:00"), by=as.nanoduration("00:00:01"), length.out=100)
dt1 <- data.table(index=t1, V1=0:99)
setkey(dt1, index)

grid.align(dt1, as.nanoduration("00:00:10"), func=colMeans)
~~~

Which produces:

~~~
                        index   V1
 1: 1970-01-01T00:00:10+00:00  4.5
 2: 1970-01-01T00:00:20+00:00 14.5
 3: 1970-01-01T00:00:30+00:00 24.5
 4: 1970-01-01T00:00:40+00:00 34.5
 5: 1970-01-01T00:00:50+00:00 44.5
 6: 1970-01-01T00:01:00+00:00 54.5
 7: 1970-01-01T00:01:10+00:00 64.5
 8: 1970-01-01T00:01:20+00:00 74.5
 9: 1970-01-01T00:01:30+00:00 84.5
10: 1970-01-01T00:01:40+00:00 94.5
~~~

#### `frequency`

Frequency is yet one abtraction higher and is basically `grid.align`
with a default function which is the counting of the number of
elements in each interval. `frequency` is in fact equivalent to a call
of `grid.align` with the function `func` being:

~~~ R
function(y) if (is.null(y)) 0 else nrow(y)
~~~

We take the same example as above and we see that the result is the
count of elements of `dt1` that are in each interval:

~~~ R
library(dtts)

t1 <- seq(as.nanotime("1970-01-01T00:00:00+00:00"), by=as.nanoduration("00:00:01"), length.out=100)
dt1 <- data.table(index=t1, V1=0:99)
setkey(dt1, index)

frequency(dt1, as.nanoduration("00:00:10"))
~~~

Which produces:

~~~
                        index V1
 1: 1970-01-01T00:00:10+00:00 10
 2: 1970-01-01T00:00:20+00:00 10
 3: 1970-01-01T00:00:30+00:00 10
 4: 1970-01-01T00:00:40+00:00 10
 5: 1970-01-01T00:00:50+00:00 10
 6: 1970-01-01T00:01:00+00:00 10
 7: 1970-01-01T00:01:10+00:00 10
 8: 1970-01-01T00:01:20+00:00 10
 9: 1970-01-01T00:01:30+00:00 10
10: 1970-01-01T00:01:40+00:00 10
~~~

## Status

`dtts` currently proposes only a set of alignment functions. "Moving"
functions such as moving sum, moving average, etc. are planned but not
yet implemented.

See the [issue tickets](https://github.com/eddelbuettel/dtts/issues)
for an up to date list of potentially desirable, possibly planned, or
at least discussed items.

## Installation

```r
remotes::install_github("eddelbuettel/dtts.utils")
```

## Author

Dirk Eddelbuettel, Leonardo Silvestri

## License

GPL (>= 2)
