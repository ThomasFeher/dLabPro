/* dLabPro class CSvm (svm)
 * - Support vector machine classifier (wraps dLabPro/ext/libsvm).
 *
 * AUTHOR : Robert Schubert
 * PACKAGE: dLabPro/classes
 *
 * This file was generated by dcg. DO NOT MODIFY! Modify svm.def instead.
 * 
 * Copyright 2013 dLabPro contributors and others (see COPYRIGHT file) 
 * - Chair of System Theory and Speech Technology, TU Dresden
 * - Chair of Communications Engineering, BTU Cottbus
 * 
 * This file is part of dLabPro.
 * 
 * dLabPro is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 * 
 * dLabPro is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with dLabPro. If not, see <http://www.gnu.org/licenses/>.
 */

#include "dlp_cscope.h" /* Indicate C scope */
/*{{CGEN_INCLUDE */
/*}}CGEN_END */
#include "dlp_svm.h"

/* Class CSvm */

void CSvm_Constructor(CSvm* _this, const char* lpInstanceName, BOOL bCallVirtual)
{
	DEBUGMSG(-1,"CSvm_Constructor; (bCallVirtual=%d)",(int)bCallVirtual,0,0);

#ifndef __cplusplus

	/* Register instance */
	dlp_xalloc_register_object('J',_this,1,sizeof(CSvm),
		__FILE__,__LINE__,"svm",lpInstanceName);

	/* Create base instance */
	_this->m_lpBaseInstance = calloc(1,sizeof(CDlpObject));
	CDlpObject_Constructor(_this->m_lpBaseInstance,lpInstanceName,FALSE);

	/* Override virtual member functions */
	_this->m_lpBaseInstance->AutoRegisterWords = CSvm_AutoRegisterWords;
	_this->m_lpBaseInstance->Reset             = CSvm_Reset;
	_this->m_lpBaseInstance->Init              = CSvm_Init;
	_this->m_lpBaseInstance->Serialize         = CSvm_Serialize;
	_this->m_lpBaseInstance->SerializeXml      = CSvm_SerializeXml;
	_this->m_lpBaseInstance->Deserialize       = CSvm_Deserialize;
	_this->m_lpBaseInstance->DeserializeXml    = CSvm_DeserializeXml;
	_this->m_lpBaseInstance->Copy              = CSvm_Copy;
	_this->m_lpBaseInstance->ClassProc         = CSvm_ClassProc;
	_this->m_lpBaseInstance->GetInstanceInfo   = CSvm_GetInstanceInfo;
	_this->m_lpBaseInstance->IsKindOf          = CSvm_IsKindOf;
	_this->m_lpBaseInstance->Destructor        = CSvm_Destructor;
	_this->m_lpBaseInstance->ResetAllOptions   = CSvm_ResetAllOptions;

	/* Override pointer to derived instance */
	_this->m_lpBaseInstance->m_lpDerivedInstance = _this;

	#endif /* #ifndef __cplusplus */

	dlp_strcpy(BASEINST(_this)->m_lpClassName,"svm");
	dlp_strcpy(BASEINST(_this)->m_lpObsoleteName,"");
	dlp_strcpy(BASEINST(_this)->m_lpProjectName,"svm");
	dlp_strcpy(BASEINST(_this)->m_version.no,"v2005.10");
	dlp_strcpy(BASEINST(_this)->m_version.date,"");
	BASEINST(_this)->m_nClStyle = CS_AUTOACTIVATE;

	if (bCallVirtual)
	{
		DLPASSERT(OK(INVOKE_VIRTUAL_0(AutoRegisterWords)));
		INVOKE_VIRTUAL_1(Init,TRUE);
	}
}

void CSvm_Destructor(CDlpObject* __this)
{
	GET_THIS_VIRTUAL(CSvm);
	{
	/*{{CGEN_DONECODE */
  DONE;
	/*}}CGEN_DONECODE */
	}

#ifndef __cplusplus

	/* Destroy base instance */
	CDlpObject_Destructor(_this->m_lpBaseInstance);
	dlp_free(_this->m_lpBaseInstance);
	_this->m_lpBaseInstance = NULL;

#endif /* #ifndef __cplusplus */
}

INT16 CSvm_AutoRegisterWords(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	DEBUGMSG(-1,"CSvm_AutoRegisterWords",0,0,0);

	/* Call base class implementation */
	IF_NOK(INVOKE_BASEINST_0(AutoRegisterWords)) return NOT_EXEC;

	/*{{CGEN_REGISTERWORDS */

	/* Register methods */
	REGISTER_METHOD("-classify","",LPMF(CSvm,OnClassify),"classify sample data from the SVM model",0,"<data testset> <data results> <svm this>","")
	REGISTER_METHOD("-crossvalidate","",LPMF(CSvm,OnCrossvalidate),"cross-validate the parameters from sample data",0,"<short n_fold> <data trainset> <svm this>","")
	REGISTER_METHOD("-is_trained","",LPMF(CSvm,OnIsTrained),"is the instance ready for classification?",0,"<svm this>","")
	REGISTER_METHOD("-status","",LPMF(CSvm,OnStatus),"print information about the parameters and model",0,"<svm this>","")
	REGISTER_METHOD("-train","",LPMF(CSvm,OnTrain),"train the SVM model from sample data",0,"<data trainset> <svm this>","")

	/* Register options */
	REGISTER_OPTION("/2norm","",LPMV(m_b2norm),LPMF(CSvm,On2normSet),"compute the 2-norm of the soft-margin slack instead of the 1-norm",0)
	REGISTER_OPTION("/hard_margin","",LPMV(m_bHardMargin),LPMF(CSvm,OnHardMarginSet),"always disallow support vectors to lie beyond their class margin",0)
	REGISTER_OPTION("/incremental","",LPMV(m_bIncremental),NULL,"improve the existing model when training with new data",0)
	REGISTER_OPTION("/newstats","",LPMV(m_bNewstats),NULL,"clear error and performance statistics before prediction",0)
	REGISTER_OPTION("/no_shrinking","",LPMV(m_bNoShrinking),NULL,"do not use shrinking heuristics when training",0)
	REGISTER_OPTION("/probabilities","",LPMV(m_bProbabilities),NULL,"estimate a-posteriori class probabilities",0)

	/* Register fields */
	REGISTER_FIELD("model_alphas","",LPMV(m_idModelAlphas),LPMF(CSvm,OnModelAlphasChanged),"alphas corresponding to support vectors of each classifier",0,6002,1,"data",NULL)
	REGISTER_FIELD("model_b","",LPMV(m_idModelB),NULL,"decision function bias (b) of each classifier",FF_NOSET,6002,1,"data",NULL)
	REGISTER_FIELD("model_classes","",LPMV(m_idModelClasses),NULL,"class labels of the training set",FF_NOSET,6002,1,"data",NULL)
	REGISTER_FIELD("model_nrfeatures","",LPMV(m_nModelNrfeatures),NULL,"dimensionality of the input space, redundant convenience attribute",FF_HIDDEN | FF_NOSET,1008,1,"unsigned long",(UINT64)0)
	REGISTER_FIELD("model_nrsamples","",LPMV(m_nModelNrsamples),NULL,"size of the previous training set, redundant convenience attribute",FF_HIDDEN | FF_NOSET,1008,1,"unsigned long",(UINT64)0)
	REGISTER_FIELD("model_prob_A","",LPMV(m_idModelProbA),NULL,"parameters A of the sigmoid class pdf estimates used for probability estimates",FF_NOSET,6002,1,"data",NULL)
	REGISTER_FIELD("model_prob_B","",LPMV(m_idModelProbB),NULL,"parameters B of the sigmoid class pdf estimates used for probability estimates",FF_NOSET,6002,1,"data",NULL)
	REGISTER_FIELD("model_SVs","",LPMV(m_idModelSVs),LPMF(CSvm,OnModelSVsChanged),"labelled support vectors",0,6002,1,"data",NULL)
	REGISTER_FIELD("param_C","",LPMV(m_nParamC),LPMF(CSvm,OnParamCChanged),"regularisation parameter, upper bound on alphas",0,3008,1,"double",(FLOAT64)1.0)
	REGISTER_FIELD("param_C_weights","",LPMV(m_idParamCWeights),LPMF(CSvm,OnParamCWeightsChanged),"factors/weights to the C parameter for each class (for unbalanced data)",0,6002,1,"data",NULL)
	REGISTER_FIELD("param_epsilon","",LPMV(m_nParamEpsilon),LPMF(CSvm,OnParamEpsilonChanged),"termination criterion tolerance",0,3008,1,"double",(FLOAT64)0.01)
	REGISTER_FIELD("param_knl_degree","",LPMV(m_nParamKnlDegree),NULL,"degree parameter in polynomial kernel",0,2002,1,"short",(INT16)2)
	REGISTER_FIELD("param_knl_gradient","",LPMV(m_nParamKnlGradient),NULL,"factor parameter in polynomial, RBF, and sigmoid kernels",0,3008,1,"double",(FLOAT64)0.0)
	REGISTER_FIELD("param_knl_offset","",LPMV(m_nParamKnlOffset),NULL,"addend parameter in polynomial and sigmoid kernels",0,3008,1,"double",(FLOAT64)0.0)
	REGISTER_FIELD("param_knl_type","",LPMV(m_nParamKnlType),LPMF(CSvm,OnParamKnlTypeChanged),"type of kernel for the implicit non-linear mapping from input to feature space",0,2002,1,"short",(INT16)SVM_KT_LINEAR)
	REGISTER_FIELD("param_threshold","",LPMV(m_nParamThreshold),LPMF(CSvm,OnParamThresholdChanged),"modulus of the decision function treshold for rejection",0,3008,1,"double",(FLOAT64)0.0)
	REGISTER_FIELD("stat_errs","",LPMV(m_idStatErrs),NULL,"statistics about mispredictions",FF_NOSET,6002,1,"data",NULL)
	REGISTER_FIELD("stat_rates","",LPMV(m_idStatRates),NULL,"statistics about precision/recall rates",FF_NOSET,6002,1,"data",NULL)

	/* Register errors */
	REGISTER_ERROR("~e1_0_0__1",EL_ERROR,SVM_NOTALLOWED,"this parameter value is forbidden (%s)")
	REGISTER_ERROR("~e2_0_0__1",EL_ERROR,SVM_LABELS,"class label is not allowed (%s)")
	REGISTER_ERROR("~e3_0_0__1",EL_WARNING,SVM_INCONSISTENT,"model is inconsistent (%s)")
	REGISTER_ERROR("~e4_0_0__1",EL_ERROR,SVM_PARAMETERS,"given problem set does not match training parameters (%s)")
	REGISTER_ERROR("~e5_0_0__1",EL_ERROR,SVM_CONVERT,"Data conversion error (%s%d%s).")
	REGISTER_ERROR("~e6_0_0__1",EL_ERROR,SVM_NOMODEL,"no consistent model available, train one first")
	REGISTER_ERROR("~e7_0_0__1",EL_ERROR,SVM_NOTIMPL,"the requested feature is not implemented, please use the customised LIBSVM")
	REGISTER_ERROR("~e8_0_0__1",EL_WARNING,SVM_LABNOTFOUND,"class label %ld not found in model")
	REGISTER_ERROR("~e9_0_0__1",EL_ERROR,SVM_INTERNAL,"Internal error (%s)")
	/*}}CGEN_REGISTERWORDS */

	return O_K;
}

INT16 CSvm_Init(CDlpObject* __this, BOOL bCallVirtual)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	DEBUGMSG(-1,"CSvm_Init, (bCallVirtual=%d)",(int)bCallVirtual,0,0);
	{
	/*{{CGEN_INITCODE */
  INIT;
	/*}}CGEN_INITCODE */
	}

	/* If last derivation call reset (do not reset members; already done by Init()) */
#ifndef __NORTTI
	if (bCallVirtual) return INVOKE_VIRTUAL_1(Reset,FALSE); else
#endif
	                  return O_K;
}

INT16 CSvm_Reset(CDlpObject* __this, BOOL bResetMembers)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	DEBUGMSG(-1,"CSvm_Reset; (bResetMembers=%d)",(int)bResetMembers,0,0);
	{
	/*{{CGEN_RESETCODE */
  return RESET;
	/*}}CGEN_RESETCODE */
	}

	return O_K;
}

INT16 CSvm_ClassProc(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
	/*{{CGEN_CLASSCODE */
  return CLASSPROC;
	/*}}CGEN_CLASSCODE */
	}

	return O_K;
}

#define CODE_DN3 /* check this for xml specific save code */
#define SAVE  SAVE_DN3
INT16 CSvm_Serialize(CDlpObject* __this, CDN3Stream* lpDest)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
	/*{{CGEN_SAVECODE */
  return SAVE;
	/*}}CGEN_SAVECODE */
	}

	return O_K;
}
#undef  SAVE
#undef  CODE_DN3

#define CODE_XML /* check this for xml specific save code */
#define SAVE  SAVE_XML
INT16 CSvm_SerializeXml(CDlpObject* __this, CXmlStream* lpDest)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
	/*{{CGEN_SAVECODE */
  return SAVE;
	/*}}CGEN_SAVECODE */
	}

	return O_K;
}
#undef  SAVE
#undef  CODE_XML

#define CODE_DN3 /* check this for dn3 specific restore code */
#define RESTORE  RESTORE_DN3
INT16 CSvm_Deserialize(CDlpObject* __this, CDN3Stream* lpSrc)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
	/*{{CGEN_RESTORECODE */
  return RESTORE;
	/*}}CGEN_RESTORECODE */
	}

	return O_K;
}
#undef  RESTORE
#undef  CODE_DN3

#define CODE_XML /* check this for xml specific restore code */
#define RESTORE  RESTORE_XML
INT16 CSvm_DeserializeXml(CDlpObject* __this, CXmlStream* lpSrc)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
	/*{{CGEN_RESTORECODE */
  return RESTORE;
	/*}}CGEN_RESTORECODE */
	}

	return O_K;
}
#undef  RESTORE
#undef  CODE_XML

INT16 CSvm_Copy(CDlpObject* __this, CDlpObject* __iSrc)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
	/*{{CGEN_COPYCODE */
  return COPY;
	/*}}CGEN_COPYCODE */
	}

	return O_K;
}

/* Runtime class type information and class factory */
INT16 CSvm_InstallProc(void* lpItp)
{
	{
	/*{{CGEN_INSTALLCODE */
  return INSTALL;
	/*}}CGEN_INSTALLCODE */
	}

	return O_K;
}

CSvm* CSvm_CreateInstance(const char* lpName)
{
	CSvm* lpNewInstance;
	ICREATEEX(CSvm,lpNewInstance,lpName,NULL);
	return lpNewInstance;
}

INT16 CSvm_GetClassInfo(SWord* lpClassWord)
{
	if (!lpClassWord) return NOT_EXEC;
	dlp_memset(lpClassWord,0,sizeof(SWord));

	lpClassWord->nWordType          = WL_TYPE_FACTORY;
	lpClassWord->nFlags             = CS_AUTOACTIVATE;

#ifdef __cplusplus

	lpClassWord->ex.fct.lpfFactory  = (LP_FACTORY_PROC)CSvm::CreateInstance;
	lpClassWord->ex.fct.lpfInstall  = CSvm::InstallProc;

#else /* #ifdef __DLP_CSCOPE */

	lpClassWord->ex.fct.lpfFactory  = (LP_FACTORY_PROC)CSvm_CreateInstance;
	lpClassWord->ex.fct.lpfInstall  = CSvm_InstallProc;

#endif /* #ifdef __DLP_CSCOPE */

	lpClassWord->ex.fct.lpProject   = "svm";
	lpClassWord->ex.fct.lpBaseClass = "-";
	lpClassWord->lpComment          = "Support vector machine classifier (wraps dLabPro/ext/libsvm).";
	lpClassWord->ex.fct.lpAutoname  = "";
	lpClassWord->ex.fct.lpCname     = "CSvm";
	lpClassWord->ex.fct.lpAuthor    = "Robert Schubert";

	dlp_strcpy(lpClassWord->lpName             ,"svm");
	dlp_strcpy(lpClassWord->lpObsname          ,"");
	dlp_strcpy(lpClassWord->ex.fct.version.no  ,"v2005.10");

	return O_K;
}

INT16 CSvm_GetInstanceInfo(CDlpObject* __this, SWord* lpClassWord)
{
	return CSvm_GetClassInfo(lpClassWord);
}

BOOL CSvm_IsKindOf(CDlpObject* __this, const char* lpClassName)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);

  if (dlp_strncmp(lpClassName,"svm",L_NAMES) == 0) return TRUE;
	else return INVOKE_BASEINST_1(IsKindOf,lpClassName);
}

INT16 CSvm_ResetAllOptions(CDlpObject* __this, BOOL bInit)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	DEBUGMSG(-1,"CSvm_ResetAllOptions;",0,0,0);
	{
	/*{{CGEN_RESETALLOPTIONS*/
	_this->m_b2norm = FALSE;
	_this->m_bHardMargin = FALSE;
	_this->m_bIncremental = FALSE;
	_this->m_bNewstats = FALSE;
	_this->m_bNoShrinking = FALSE;
	_this->m_bProbabilities = FALSE;
	/*}}CGEN_RESETALLOPTIONS*/
	}

	return INVOKE_BASEINST_1(ResetAllOptions,bInit);
}

/* Generated primary method invocation functions */

#ifndef __NOITP
/*{{CGEN_CPMIC */
INT16 CSvm_OnClassify(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* testset;
	data* results;
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	results = MIC_GET_I_EX(results,data,1,1);
	testset = MIC_GET_I_EX(testset,data,2,2);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CSvm_Classify(_this, testset, results);
	return __nErr;
}

INT16 CSvm_OnCrossvalidate(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	INT16 n_fold;
	data* trainset;
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	trainset = MIC_GET_I_EX(trainset,data,1,1);
	n_fold = (INT16)MIC_GET_N(2,0);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	MIC_PUT_N(CSvm_Crossvalidate(_this, n_fold, trainset));
	return __nErr;
}

INT16 CSvm_OnIsTrained(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	MIC_PUT_B(CSvm_IsTrained(_this));
	return __nErr;
}

INT16 CSvm_OnStatus(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CSvm_Status(_this);
	return __nErr;
}

INT16 CSvm_OnTrain(CDlpObject* __this)
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	INT16 __nErr    = O_K;
	INT32  __nErrCnt = 0;
	data* trainset;
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	MIC_CHECK;
	__nErrCnt = CDlpObject_GetErrorCount();
	trainset = MIC_GET_I_EX(trainset,data,1,1);
	if (CDlpObject_GetErrorCount()>__nErrCnt) return NOT_EXEC;
	__nErr = CSvm_Train(_this, trainset);
	return __nErr;
}

/*}}CGEN_CPMIC */
#endif /* #ifndef __NOITP */


/* Generated secondary method invocation functions */

/*{{CGEN_CSMIC */
/*}}CGEN_CSMIC */


/* Generated option change callback functions */

/*{{CGEN_COCCF */
INT16 CSvm_On2normSet(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
  #ifndef __NEW_LIBSVM_INTERFACE
   _this->m_b2norm = FALSE;
   ERRORMSG(SVM_NOTIMPL, 0, 0, 0, SVM_NOTIMPL);
  #else
   if (_this->m_bHardMargin)
   {
    _this->m_b2norm = FALSE;
    return IERROR(_this,SVM_NOTALLOWED,         "/2norm is a soft-margin option but we run /hard_margin", 0, 0);
   }
   else
   {
   }
  #endif
	}

	return O_K;
}

INT16 CSvm_OnHardMarginSet(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
   if (_this->m_b2norm)
   {
    _this->m_bHardMargin = FALSE;
    return IERROR(_this,SVM_NOTALLOWED,         "/hard_margin not possible with explicit soft-margin option /2norm enabled", 0, 0);
   }
   else
    printf (         "warning: the values of param_C and param_C_weights will be ignored\n");
	}

	return O_K;
}

/*}}CGEN_COCCF */


/* Generated field change callback functions */

/*{{CGEN_CFCCF */
INT16 CSvm_OnModelAlphasChanged(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
   printf(        "careful: make sure this change is consistent with model_SVs\n");
	}

	return O_K;
}

INT16 CSvm_OnModelSVsChanged(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
   printf(          "careful: make sure this change is consistent with model_alphas and model_classes\n");
	}

	return O_K;
}

INT16 CSvm_OnParamCChanged(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
   if (_this->m_nParamC <= 0)
    return IERROR(_this,SVM_NOTALLOWED,  " <= 0", 0, 0);
	}

	return O_K;
}

INT16 CSvm_OnParamCWeightsChanged(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
   if (2 != CData_GetNComps(_this->m_idParamCWeights)      || !dlp_is_integer_type_code(CData_GetCompType(_this->m_idParamCWeights, 0))      || !dlp_is_float_type_code(CData_GetCompType(_this->m_idParamCWeights, 1)))
   {
    return IERROR(_this,SVM_NOTALLOWED,       "first column must be labels, second column weights",0,0);
   }
   else
   {
   if (_this->m_idModelClasses)
    if (CData_GetNRecs(_this->m_idModelClasses) != CData_GetNRecs(_this->m_idParamCWeights))
     printf(               "warning: number of C weights different from the number of classes in the last training set\n");
   }
	}

	return O_K;
}

INT16 CSvm_OnParamEpsilonChanged(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
   if (_this->m_nParamEpsilon <= 0 || _this->m_nParamEpsilon >= 1)
    return IERROR(_this,SVM_NOTALLOWED,      "value must fall in the interval (0,1)",0,0);
	}

	return O_K;
}

INT16 CSvm_OnParamKnlTypeChanged(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
   char gradientexplanation[80];
   if (_this->m_nParamKnlGradient)
    sprintf(gradientexplanation, "%.5f", (FLOAT32)_this->m_nParamKnlGradient);
   else
    sprintf(gradientexplanation, "1/nr_features");

   switch (_this->m_nParamKnlType)
   {
    case SVM_KT_LINEAR:
      IFCHECK
        printf(    "kernel K(x,y) will be (x'*y)\n");
      break;
    case SVM_KT_POLY:
      IFCHECK
        printf(      "kernel K(x,y) will be (%s*x'*y + %.2f)^%d\n", gradientexplanation, (FLOAT32)_this->m_nParamKnlOffset, (int)_this->m_nParamKnlDegree);
      break;
    case SVM_KT_RBF:
      IFCHECK
        printf(    "kernel K(x,y) will be exp(-%s*(x-y)'*(x-y))\n", gradientexplanation);
      break;
    case SVM_KT_SIGMOID:
      IFCHECK
        printf(      "kernel K(x,y) will be tanh(%s*x'*y + %.2f)\n", gradientexplanation, (FLOAT32)_this->m_nParamKnlOffset);
      break;
    default:
      return IERROR(_this,SVM_NOTALLOWED,           "must be one of 0 (linear), 1 (polynomial), 2 (RBF), 3 (sigmoid)", 0, 0);
   }
	}

	return O_K;
}

INT16 CSvm_OnParamThresholdChanged(CDlpObject* __this)
{
	GET_THIS_VIRTUAL_RV(CSvm,NOT_EXEC);
	{
  #ifndef __NEW_LIBSVM_INTERFACE
   IERROR(_this,SVM_NOTIMPL, 0, 0, 0, SVM_NOTIMPL);
  #else
   if (_this->m_nParamThreshold < 0 || _this->m_nParamThreshold > 1)
    return IERROR(_this,SVM_NOTALLOWED,      "value must fall in the interval [0,1]",0,0);
  #endif
	}

	return O_K;
}

/*}}CGEN_CFCCF */


/* C++ wrapper functions */
#ifdef __cplusplus

#define _this this

CSvm::CSvm(const char* lpInstanceName, BOOL bCallVirtual) : inherited(lpInstanceName,0)
{
	CSvm_Constructor(this,lpInstanceName,bCallVirtual);
}

CSvm::~CSvm()
{
	CSvm_Destructor(this);
}

INT16 CSvm::AutoRegisterWords()
{
	return CSvm_AutoRegisterWords(this);
}

INT16 CSvm::Init(BOOL bCallVirtual)
{
	return CSvm_Init(this,bCallVirtual);
}

INT16 CSvm::Reset(BOOL bResetMembers)
{
	return CSvm_Reset(this,bResetMembers);
}

INT16 CSvm::ClassProc()
{
	return CSvm_ClassProc(this);
}

INT16 CSvm::Serialize(CDN3Stream* lpDest)
{
	return CSvm_Serialize(this,lpDest);
}

INT16 CSvm::SerializeXml(CXmlStream* lpDest)
{
	return CSvm_SerializeXml(this,lpDest);
}

INT16 CSvm::Deserialize(CDN3Stream* lpSrc)
{
	return CSvm_Deserialize(this,lpSrc);
}

INT16 CSvm::DeserializeXml(CXmlStream* lpSrc)
{
	return CSvm_DeserializeXml(this,lpSrc);
}

INT16 CSvm::Copy(CDlpObject* __iSrc)
{
	return CSvm_Copy(this,__iSrc);
}

INT16 CSvm::InstallProc(void* lpItp)
{
	return CSvm_InstallProc(lpItp);
}

CSvm* CSvm::CreateInstance(const char* lpName)
{
	return CSvm_CreateInstance(lpName);
}

INT16 CSvm::GetClassInfo(SWord* lpClassWord)
{
	return CSvm_GetClassInfo(lpClassWord);
}

INT16 CSvm::GetInstanceInfo(SWord* lpClassWord)
{
	return CSvm_GetInstanceInfo(this,lpClassWord);
}

BOOL CSvm::IsKindOf(const char* lpClassName)
{
	return CSvm_IsKindOf(this,lpClassName);
}

INT16 CSvm::ResetAllOptions(BOOL bInit)
{
	return CSvm_ResetAllOptions(this,bInit);
}

#ifndef __NOITP
/*{{CGEN_PMIC */
INT16 CSvm::OnClassify()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CSvm_OnClassify(this);
}

INT16 CSvm::OnCrossvalidate()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CSvm_OnCrossvalidate(this);
}

INT16 CSvm::OnIsTrained()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CSvm_OnIsTrained(this);
}

INT16 CSvm::OnStatus()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CSvm_OnStatus(this);
}

INT16 CSvm::OnTrain()
/* DO NOT CALL THIS FUNCTION FROM C++ SCOPE.     */
/* IT MAY INTERFERE WITH THE INTERPRETER SESSION */
{
	return CSvm_OnTrain(this);
}

/*}}CGEN_PMIC */
#endif /* #ifndef __NOITP */

/*{{CGEN_SMIC */
/*}}CGEN_SMIC */

/*{{CGEN_OCCF */
INT16 CSvm::On2normSet()
{
	return CSvm_On2normSet(this);
}

INT16 CSvm::OnHardMarginSet()
{
	return CSvm_OnHardMarginSet(this);
}

/*}}CGEN_OCCF */

/*{{CGEN_FCCF */
INT16 CSvm::OnModelAlphasChanged()
{
	return CSvm_OnModelAlphasChanged(this);
}

INT16 CSvm::OnModelSVsChanged()
{
	return CSvm_OnModelSVsChanged(this);
}

INT16 CSvm::OnParamCChanged()
{
	return CSvm_OnParamCChanged(this);
}

INT16 CSvm::OnParamCWeightsChanged()
{
	return CSvm_OnParamCWeightsChanged(this);
}

INT16 CSvm::OnParamEpsilonChanged()
{
	return CSvm_OnParamEpsilonChanged(this);
}

INT16 CSvm::OnParamKnlTypeChanged()
{
	return CSvm_OnParamKnlTypeChanged(this);
}

INT16 CSvm::OnParamThresholdChanged()
{
	return CSvm_OnParamThresholdChanged(this);
}

/*}}CGEN_FCCF */

/*{{CGEN_CXXWRAP */
void CSvm::toParameters(struct svm_parameter* param)
{
	CSvm_toParameters(this, param);
}

bool CSvm::toProblemSet(CData* idTset, struct svm_problem* lpPrblm)
{
	return CSvm_toProblemSet(this, idTset, lpPrblm);
}

bool CSvm::fromModel(struct svm_model* newmodel)
{
	return CSvm_fromModel(this, newmodel);
}

bool CSvm::toModel(struct svm_model* model)
{
	return CSvm_toModel(this, model);
}

FLOAT64 CSvm::Crossvalidate(INT16 n_fold, data* trainset)
{
	return CSvm_Crossvalidate(this, n_fold, trainset);
}

INT16 CSvm::Train(data* trainset)
{
	return CSvm_Train(this, trainset);
}

INT16 CSvm::TrainIncremental(CData* trainset)
{
	return CSvm_TrainIncremental(this, trainset);
}

BOOL CSvm::IsTrained()
{
	return CSvm_IsTrained(this);
}

INT16 CSvm::Classify(data* testset, data* results)
{
	return CSvm_Classify(this, testset, results);
}

INT16 CSvm::Status()
{
	return CSvm_Status(this);
}

/*}}CGEN_CXXWRAP */

#endif /* #ifdef __cplusplus */

/* EOF */