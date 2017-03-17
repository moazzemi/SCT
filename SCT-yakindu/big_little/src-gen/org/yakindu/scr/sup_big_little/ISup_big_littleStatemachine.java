package org.yakindu.scr.sup_big_little;

import org.yakindu.scr.IStatemachine;

public interface ISup_big_littleStatemachine extends IStatemachine {

	public interface SCIPC {
	
		public void raiseCritical();
		
		public void raiseSafeP();
		
		public void raiseControlP();
		
		public void raiseSafeEval();
		
	}
	
	public SCIPC getSCIPC();
	
	public interface SCIHR {
	
		public void raiseHRmet1();
		
		public void raiseHRnotMet1();
		
		public void raiseHRmet2();
		
		public void raiseHRnotMet2();
		
	}
	
	public SCIHR getSCIHR();
	
	public interface SCISafe {
	
		public void raiseMet1();
		
		public void raiseNotMet1();
		
		public void raiseMet2();
		
		public void raiseNotMet2();
		
	}
	
	public SCISafe getSCISafe();
	
	public interface SCIPower {
	
		public void raiseDecreaseP1();
		
		public void raiseDecreaseP2();
		
		public void raiseIncreaseP1();
		
		public void raiseIncreaseP2();
		
		public void raiseDecreaseCriticalP1();
		
		public void raiseDecreaseCriticalP2();
		
	}
	
	public SCIPower getSCIPower();
	
}
