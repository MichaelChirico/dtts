// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// align_duration
Rcpp::List align_duration(const Rcpp::NumericVector& x, const Rcpp::NumericVector& y, const Rcpp::List xdata, const Rcpp::NumericVector& start, const Rcpp::NumericVector& end, const Rcpp::LogicalVector& sopen, const Rcpp::LogicalVector& eopen, const Rcpp::Function func);
RcppExport SEXP _dtts_align_duration(SEXP xSEXP, SEXP ySEXP, SEXP xdataSEXP, SEXP startSEXP, SEXP endSEXP, SEXP sopenSEXP, SEXP eopenSEXP, SEXP funcSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const Rcpp::List >::type xdata(xdataSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type start(startSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type end(endSEXP);
    Rcpp::traits::input_parameter< const Rcpp::LogicalVector& >::type sopen(sopenSEXP);
    Rcpp::traits::input_parameter< const Rcpp::LogicalVector& >::type eopen(eopenSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Function >::type func(funcSEXP);
    rcpp_result_gen = Rcpp::wrap(align_duration(x, y, xdata, start, end, sopen, eopen, func));
    return rcpp_result_gen;
END_RCPP
}
// align_period
Rcpp::List align_period(const Rcpp::NumericVector& x, const Rcpp::NumericVector& y, const Rcpp::List xdata, const Rcpp::ComplexVector& start, const Rcpp::ComplexVector& end, const Rcpp::LogicalVector& sopen, const Rcpp::LogicalVector& eopen, const Rcpp::Function func, const Rcpp::CharacterVector tz);
RcppExport SEXP _dtts_align_period(SEXP xSEXP, SEXP ySEXP, SEXP xdataSEXP, SEXP startSEXP, SEXP endSEXP, SEXP sopenSEXP, SEXP eopenSEXP, SEXP funcSEXP, SEXP tzSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const Rcpp::List >::type xdata(xdataSEXP);
    Rcpp::traits::input_parameter< const Rcpp::ComplexVector& >::type start(startSEXP);
    Rcpp::traits::input_parameter< const Rcpp::ComplexVector& >::type end(endSEXP);
    Rcpp::traits::input_parameter< const Rcpp::LogicalVector& >::type sopen(sopenSEXP);
    Rcpp::traits::input_parameter< const Rcpp::LogicalVector& >::type eopen(eopenSEXP);
    Rcpp::traits::input_parameter< const Rcpp::Function >::type func(funcSEXP);
    Rcpp::traits::input_parameter< const Rcpp::CharacterVector >::type tz(tzSEXP);
    rcpp_result_gen = Rcpp::wrap(align_period(x, y, xdata, start, end, sopen, eopen, func, tz));
    return rcpp_result_gen;
END_RCPP
}
// align_idx_duration
Rcpp::NumericVector align_idx_duration(const Rcpp::NumericVector& x, const Rcpp::NumericVector& y, const Rcpp::NumericVector& start, const Rcpp::NumericVector& end, const Rcpp::LogicalVector& sopen, const Rcpp::LogicalVector& eopen);
RcppExport SEXP _dtts_align_idx_duration(SEXP xSEXP, SEXP ySEXP, SEXP startSEXP, SEXP endSEXP, SEXP sopenSEXP, SEXP eopenSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type start(startSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type end(endSEXP);
    Rcpp::traits::input_parameter< const Rcpp::LogicalVector& >::type sopen(sopenSEXP);
    Rcpp::traits::input_parameter< const Rcpp::LogicalVector& >::type eopen(eopenSEXP);
    rcpp_result_gen = Rcpp::wrap(align_idx_duration(x, y, start, end, sopen, eopen));
    return rcpp_result_gen;
END_RCPP
}
// align_idx_period
Rcpp::NumericVector align_idx_period(const Rcpp::NumericVector& x, const Rcpp::NumericVector& y, const Rcpp::ComplexVector& start, const Rcpp::ComplexVector& end, const Rcpp::LogicalVector& sopen, const Rcpp::LogicalVector& eopen, const Rcpp::CharacterVector& tz);
RcppExport SEXP _dtts_align_idx_period(SEXP xSEXP, SEXP ySEXP, SEXP startSEXP, SEXP endSEXP, SEXP sopenSEXP, SEXP eopenSEXP, SEXP tzSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const Rcpp::NumericVector& >::type y(ySEXP);
    Rcpp::traits::input_parameter< const Rcpp::ComplexVector& >::type start(startSEXP);
    Rcpp::traits::input_parameter< const Rcpp::ComplexVector& >::type end(endSEXP);
    Rcpp::traits::input_parameter< const Rcpp::LogicalVector& >::type sopen(sopenSEXP);
    Rcpp::traits::input_parameter< const Rcpp::LogicalVector& >::type eopen(eopenSEXP);
    Rcpp::traits::input_parameter< const Rcpp::CharacterVector& >::type tz(tzSEXP);
    rcpp_result_gen = Rcpp::wrap(align_idx_period(x, y, start, end, sopen, eopen, tz));
    return rcpp_result_gen;
END_RCPP
}
// ops
Rcpp::List ops(Rcpp::List& xdata, Rcpp::List& ydata, Rcpp::String& op_string);
RcppExport SEXP _dtts_ops(SEXP xdataSEXP, SEXP ydataSEXP, SEXP op_stringSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List& >::type xdata(xdataSEXP);
    Rcpp::traits::input_parameter< Rcpp::List& >::type ydata(ydataSEXP);
    Rcpp::traits::input_parameter< Rcpp::String& >::type op_string(op_stringSEXP);
    rcpp_result_gen = Rcpp::wrap(ops(xdata, ydata, op_string));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_dtts_align_duration", (DL_FUNC) &_dtts_align_duration, 8},
    {"_dtts_align_period", (DL_FUNC) &_dtts_align_period, 9},
    {"_dtts_align_idx_duration", (DL_FUNC) &_dtts_align_idx_duration, 6},
    {"_dtts_align_idx_period", (DL_FUNC) &_dtts_align_idx_period, 7},
    {"_dtts_ops", (DL_FUNC) &_dtts_ops, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_dtts(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
