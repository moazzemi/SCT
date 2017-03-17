function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "C:\\Users\\kmoaz_000\\Documents\\MATLAB\\projects\\SCT\\work\\supervisor_big_little_ert_rtw\\supervisor_big_little.c",
	size: 4};
	 this.metricsArray.var["rtM_"] = {file: "C:\\Users\\kmoaz_000\\Documents\\MATLAB\\projects\\SCT\\work\\supervisor_big_little_ert_rtw\\supervisor_big_little.c",
	size: 4};
	 this.metricsArray.var["rtPrevZCX"] = {file: "C:\\Users\\kmoaz_000\\Documents\\MATLAB\\projects\\SCT\\work\\supervisor_big_little_ert_rtw\\supervisor_big_little.c",
	size: 10};
	 this.metricsArray.fcn["supervisor_big_little_initialize"] = {file: "C:\\Users\\kmoaz_000\\Documents\\MATLAB\\projects\\SCT\\work\\supervisor_big_little_ert_rtw\\supervisor_big_little.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["supervisor_big_little_step"] = {file: "C:\\Users\\kmoaz_000\\Documents\\MATLAB\\projects\\SCT\\work\\supervisor_big_little_ert_rtw\\supervisor_big_little.c",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data;}
}
	 CodeMetrics.instance = new CodeMetrics();
