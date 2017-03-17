package org.yakindu.scr.sup_big_little;

public class Sup_big_littleStatemachine implements ISup_big_littleStatemachine {

	protected class SCIPCImpl implements SCIPC {
	
		private boolean critical;
		
		public void raiseCritical() {
			critical = true;
		}
		
		private boolean safeP;
		
		public void raiseSafeP() {
			safeP = true;
		}
		
		private boolean controlP;
		
		public void raiseControlP() {
			controlP = true;
		}
		
		private boolean safeEval;
		
		public void raiseSafeEval() {
			safeEval = true;
		}
		
		protected void clearEvents() {
			critical = false;
			safeP = false;
			controlP = false;
			safeEval = false;
		}
	}
	
	protected SCIPCImpl sCIPC;
	
	protected class SCIHRImpl implements SCIHR {
	
		private boolean hRmet1;
		
		public void raiseHRmet1() {
			hRmet1 = true;
		}
		
		private boolean hRnotMet1;
		
		public void raiseHRnotMet1() {
			hRnotMet1 = true;
		}
		
		private boolean hRmet2;
		
		public void raiseHRmet2() {
			hRmet2 = true;
		}
		
		private boolean hRnotMet2;
		
		public void raiseHRnotMet2() {
			hRnotMet2 = true;
		}
		
		protected void clearEvents() {
			hRmet1 = false;
			hRnotMet1 = false;
			hRmet2 = false;
			hRnotMet2 = false;
		}
	}
	
	protected SCIHRImpl sCIHR;
	
	protected class SCISafeImpl implements SCISafe {
	
		private boolean met1;
		
		public void raiseMet1() {
			met1 = true;
		}
		
		private boolean notMet1;
		
		public void raiseNotMet1() {
			notMet1 = true;
		}
		
		private boolean met2;
		
		public void raiseMet2() {
			met2 = true;
		}
		
		private boolean notMet2;
		
		public void raiseNotMet2() {
			notMet2 = true;
		}
		
		protected void clearEvents() {
			met1 = false;
			notMet1 = false;
			met2 = false;
			notMet2 = false;
		}
	}
	
	protected SCISafeImpl sCISafe;
	
	protected class SCIPowerImpl implements SCIPower {
	
		private boolean decreaseP1;
		
		public void raiseDecreaseP1() {
			decreaseP1 = true;
		}
		
		private boolean decreaseP2;
		
		public void raiseDecreaseP2() {
			decreaseP2 = true;
		}
		
		private boolean increaseP1;
		
		public void raiseIncreaseP1() {
			increaseP1 = true;
		}
		
		private boolean increaseP2;
		
		public void raiseIncreaseP2() {
			increaseP2 = true;
		}
		
		private boolean decreaseCriticalP1;
		
		public void raiseDecreaseCriticalP1() {
			decreaseCriticalP1 = true;
		}
		
		private boolean decreaseCriticalP2;
		
		public void raiseDecreaseCriticalP2() {
			decreaseCriticalP2 = true;
		}
		
		protected void clearEvents() {
			decreaseP1 = false;
			decreaseP2 = false;
			increaseP1 = false;
			increaseP2 = false;
			decreaseCriticalP1 = false;
			decreaseCriticalP2 = false;
		}
	}
	
	protected SCIPowerImpl sCIPower;
	
	private boolean initialized = false;
	
	public enum State {
		main_region_QosMet1_QosMet2,
		main_region_DangerPower,
		main_region_PowerCap,
		main_region_SafeEval1_QosMet2,
		main_region_SafeEval1_QosNotMet2,
		main_region_QosMet1_SafeEval2,
		main_region_QosNotMet1_SafeEval2,
		main_region_SafeEval1_SafeEval2,
		main_region_SwitchGains,
		main_region_QosMet1_QosNotMet2,
		main_region_QosNotMet1_QosMet2,
		main_region_QosNotMet1_QosNotMet2,
		$NullState$
	};
	
	private final State[] stateVector = new State[1];
	
	private int nextStateIndex;
	
	public Sup_big_littleStatemachine() {
		sCIPC = new SCIPCImpl();
		sCIHR = new SCIHRImpl();
		sCISafe = new SCISafeImpl();
		sCIPower = new SCIPowerImpl();
	}
	
	public void init() {
		this.initialized = true;
		for (int i = 0; i < 1; i++) {
			stateVector[i] = State.$NullState$;
		}
		clearEvents();
		clearOutEvents();
	}
	
	public void enter() {
		if (!initialized) {
			throw new IllegalStateException(
					"The state machine needs to be initialized first by calling the init() function.");
		}
		enterSequence_main_region_default();
	}
	
	public void exit() {
		exitSequence_main_region();
	}
	
	/**
	 * @see IStatemachine#isActive()
	 */
	public boolean isActive() {
		return stateVector[0] != State.$NullState$;
	}
	
	/** 
	* Always returns 'false' since this state machine can never become final.
	*
	* @see IStatemachine#isFinal()
	*/
	public boolean isFinal() {
		return false;
	}
	/**
	* This method resets the incoming events (time events included).
	*/
	protected void clearEvents() {
		sCIPC.clearEvents();
		sCIHR.clearEvents();
		sCISafe.clearEvents();
		sCIPower.clearEvents();
	}
	
	/**
	* This method resets the outgoing events.
	*/
	protected void clearOutEvents() {
	}
	
	/**
	* Returns true if the given state is currently active otherwise false.
	*/
	public boolean isStateActive(State state) {
	
		switch (state) {
		case main_region_QosMet1_QosMet2:
			return stateVector[0] == State.main_region_QosMet1_QosMet2;
		case main_region_DangerPower:
			return stateVector[0] == State.main_region_DangerPower;
		case main_region_PowerCap:
			return stateVector[0] == State.main_region_PowerCap;
		case main_region_SafeEval1_QosMet2:
			return stateVector[0] == State.main_region_SafeEval1_QosMet2;
		case main_region_SafeEval1_QosNotMet2:
			return stateVector[0] == State.main_region_SafeEval1_QosNotMet2;
		case main_region_QosMet1_SafeEval2:
			return stateVector[0] == State.main_region_QosMet1_SafeEval2;
		case main_region_QosNotMet1_SafeEval2:
			return stateVector[0] == State.main_region_QosNotMet1_SafeEval2;
		case main_region_SafeEval1_SafeEval2:
			return stateVector[0] == State.main_region_SafeEval1_SafeEval2;
		case main_region_SwitchGains:
			return stateVector[0] == State.main_region_SwitchGains;
		case main_region_QosMet1_QosNotMet2:
			return stateVector[0] == State.main_region_QosMet1_QosNotMet2;
		case main_region_QosNotMet1_QosMet2:
			return stateVector[0] == State.main_region_QosNotMet1_QosMet2;
		case main_region_QosNotMet1_QosNotMet2:
			return stateVector[0] == State.main_region_QosNotMet1_QosNotMet2;
		default:
			return false;
		}
	}
	
	public SCIPC getSCIPC() {
		return sCIPC;
	}
	
	public SCIHR getSCIHR() {
		return sCIHR;
	}
	
	public SCISafe getSCISafe() {
		return sCISafe;
	}
	
	public SCIPower getSCIPower() {
		return sCIPower;
	}
	
	private boolean check_main_region_QosMet1_QosMet2_tr0_tr0() {
		return sCIPC.critical;
	}
	
	private boolean check_main_region_QosMet1_QosMet2_tr1_tr1() {
		return sCIHR.hRnotMet2;
	}
	
	private boolean check_main_region_QosMet1_QosMet2_tr2_tr2() {
		return sCIHR.hRnotMet1;
	}
	
	private boolean check_main_region_QosMet1_QosMet2_tr3_tr3() {
		return sCIPower.decreaseP1;
	}
	
	private boolean check_main_region_QosMet1_QosMet2_tr4_tr4() {
		return sCIPower.decreaseP2;
	}
	
	private boolean check_main_region_DangerPower_tr0_tr0() {
		return sCIPC.safeP;
	}
	
	private boolean check_main_region_DangerPower_tr1_tr1() {
		return sCIPower.decreaseCriticalP1;
	}
	
	private boolean check_main_region_DangerPower_tr2_tr2() {
		return sCIPower.decreaseCriticalP2;
	}
	
	private boolean check_main_region_PowerCap_tr0_tr0() {
		return sCIPC.critical;
	}
	
	private boolean check_main_region_PowerCap_tr1_tr1() {
		return sCIPC.safeP;
	}
	
	private boolean check_main_region_PowerCap_tr2_tr2() {
		return sCIPower.decreaseCriticalP1;
	}
	
	private boolean check_main_region_PowerCap_tr3_tr3() {
		return sCIPower.decreaseCriticalP2;
	}
	
	private boolean check_main_region_SafeEval1_QosMet2_tr0_tr0() {
		return sCISafe.met1;
	}
	
	private boolean check_main_region_SafeEval1_QosMet2_tr1_tr1() {
		return sCIHR.hRnotMet2;
	}
	
	private boolean check_main_region_SafeEval1_QosMet2_tr2_tr2() {
		return sCIHR.hRnotMet1;
	}
	
	private boolean check_main_region_SafeEval1_QosMet2_tr3_tr3() {
		return sCIPower.decreaseP2;
	}
	
	private boolean check_main_region_SafeEval1_QosNotMet2_tr0_tr0() {
		return sCIHR.hRmet2;
	}
	
	private boolean check_main_region_SafeEval1_QosNotMet2_tr1_tr1() {
		return sCISafe.met1;
	}
	
	private boolean check_main_region_SafeEval1_QosNotMet2_tr2_tr2() {
		return sCISafe.notMet1;
	}
	
	private boolean check_main_region_SafeEval1_QosNotMet2_tr3_tr3() {
		return sCIPower.increaseP2;
	}
	
	private boolean check_main_region_QosMet1_SafeEval2_tr0_tr0() {
		return sCISafe.met2;
	}
	
	private boolean check_main_region_QosMet1_SafeEval2_tr1_tr1() {
		return sCISafe.notMet2;
	}
	
	private boolean check_main_region_QosMet1_SafeEval2_tr2_tr2() {
		return sCIHR.hRnotMet1;
	}
	
	private boolean check_main_region_QosMet1_SafeEval2_tr3_tr3() {
		return sCIPower.decreaseP1;
	}
	
	private boolean check_main_region_QosNotMet1_SafeEval2_tr0_tr0() {
		return sCIHR.hRmet1;
	}
	
	private boolean check_main_region_QosNotMet1_SafeEval2_tr1_tr1() {
		return sCISafe.met2;
	}
	
	private boolean check_main_region_QosNotMet1_SafeEval2_tr2_tr2() {
		return sCISafe.notMet2;
	}
	
	private boolean check_main_region_QosNotMet1_SafeEval2_tr3_tr3() {
		return sCIPower.increaseP1;
	}
	
	private boolean check_main_region_SafeEval1_SafeEval2_tr0_tr0() {
		return sCIHR.hRnotMet1;
	}
	
	private boolean check_main_region_SafeEval1_SafeEval2_tr1_tr1() {
		return sCIHR.hRmet1;
	}
	
	private boolean check_main_region_SafeEval1_SafeEval2_tr2_tr2() {
		return sCIHR.hRnotMet2;
	}
	
	private boolean check_main_region_SafeEval1_SafeEval2_tr3_tr3() {
		return sCIHR.hRmet2;
	}
	
	private boolean check_main_region_SwitchGains_tr0_tr0() {
		return sCIPC.controlP;
	}
	
	private boolean check_main_region_SwitchGains_tr1_tr1() {
		return sCIPC.safeEval;
	}
	
	private boolean check_main_region_QosMet1_QosNotMet2_tr0_tr0() {
		return sCIPC.critical;
	}
	
	private boolean check_main_region_QosMet1_QosNotMet2_tr1_tr1() {
		return sCIHR.hRmet2;
	}
	
	private boolean check_main_region_QosMet1_QosNotMet2_tr2_tr2() {
		return sCIHR.hRnotMet1;
	}
	
	private boolean check_main_region_QosMet1_QosNotMet2_tr3_tr3() {
		return sCIPower.decreaseP1;
	}
	
	private boolean check_main_region_QosMet1_QosNotMet2_tr4_tr4() {
		return sCIPower.increaseP2;
	}
	
	private boolean check_main_region_QosNotMet1_QosMet2_tr0_tr0() {
		return sCIPC.critical;
	}
	
	private boolean check_main_region_QosNotMet1_QosMet2_tr1_tr1() {
		return sCIHR.hRmet1;
	}
	
	private boolean check_main_region_QosNotMet1_QosMet2_tr2_tr2() {
		return sCIHR.hRnotMet2;
	}
	
	private boolean check_main_region_QosNotMet1_QosMet2_tr3_tr3() {
		return sCIPower.increaseP1;
	}
	
	private boolean check_main_region_QosNotMet1_QosMet2_tr4_tr4() {
		return sCIPower.decreaseP1;
	}
	
	private boolean check_main_region_QosNotMet1_QosNotMet2_tr0_tr0() {
		return sCIPC.critical;
	}
	
	private boolean check_main_region_QosNotMet1_QosNotMet2_tr1_tr1() {
		return sCIHR.hRmet1;
	}
	
	private boolean check_main_region_QosNotMet1_QosNotMet2_tr2_tr2() {
		return sCIHR.hRmet2;
	}
	
	private boolean check_main_region_QosNotMet1_QosNotMet2_tr3_tr3() {
		return sCIPower.increaseP2;
	}
	
	private boolean check_main_region_QosNotMet1_QosNotMet2_tr4_tr4() {
		return sCIPower.increaseP1;
	}
	
	private void effect_main_region_QosMet1_QosMet2_tr0() {
		exitSequence_main_region_QosMet1_QosMet2();
		enterSequence_main_region_SwitchGains_default();
	}
	
	private void effect_main_region_QosMet1_QosMet2_tr1() {
		exitSequence_main_region_QosMet1_QosMet2();
		enterSequence_main_region_QosMet1_QosNotMet2_default();
	}
	
	private void effect_main_region_QosMet1_QosMet2_tr2() {
		exitSequence_main_region_QosMet1_QosMet2();
		enterSequence_main_region_QosNotMet1_QosMet2_default();
	}
	
	private void effect_main_region_QosMet1_QosMet2_tr3() {
		exitSequence_main_region_QosMet1_QosMet2();
		enterSequence_main_region_QosMet1_QosMet2_default();
	}
	
	private void effect_main_region_QosMet1_QosMet2_tr4() {
		exitSequence_main_region_QosMet1_QosMet2();
		enterSequence_main_region_QosMet1_QosMet2_default();
	}
	
	private void effect_main_region_DangerPower_tr0() {
		exitSequence_main_region_DangerPower();
		enterSequence_main_region_PowerCap_default();
	}
	
	private void effect_main_region_DangerPower_tr1() {
		exitSequence_main_region_DangerPower();
		enterSequence_main_region_DangerPower_default();
	}
	
	private void effect_main_region_DangerPower_tr2() {
		exitSequence_main_region_DangerPower();
		enterSequence_main_region_DangerPower_default();
	}
	
	private void effect_main_region_PowerCap_tr0() {
		exitSequence_main_region_PowerCap();
		enterSequence_main_region_DangerPower_default();
	}
	
	private void effect_main_region_PowerCap_tr1() {
		exitSequence_main_region_PowerCap();
		enterSequence_main_region_SwitchGains_default();
	}
	
	private void effect_main_region_PowerCap_tr2() {
		exitSequence_main_region_PowerCap();
		enterSequence_main_region_PowerCap_default();
	}
	
	private void effect_main_region_PowerCap_tr3() {
		exitSequence_main_region_PowerCap();
		enterSequence_main_region_PowerCap_default();
	}
	
	private void effect_main_region_SafeEval1_QosMet2_tr0() {
		exitSequence_main_region_SafeEval1_QosMet2();
		enterSequence_main_region_QosMet1_QosMet2_default();
	}
	
	private void effect_main_region_SafeEval1_QosMet2_tr1() {
		exitSequence_main_region_SafeEval1_QosMet2();
		enterSequence_main_region_SafeEval1_QosNotMet2_default();
	}
	
	private void effect_main_region_SafeEval1_QosMet2_tr2() {
		exitSequence_main_region_SafeEval1_QosMet2();
		enterSequence_main_region_QosNotMet1_QosMet2_default();
	}
	
	private void effect_main_region_SafeEval1_QosMet2_tr3() {
		exitSequence_main_region_SafeEval1_QosMet2();
		enterSequence_main_region_SafeEval1_QosMet2_default();
	}
	
	private void effect_main_region_SafeEval1_QosNotMet2_tr0() {
		exitSequence_main_region_SafeEval1_QosNotMet2();
		enterSequence_main_region_SafeEval1_QosMet2_default();
	}
	
	private void effect_main_region_SafeEval1_QosNotMet2_tr1() {
		exitSequence_main_region_SafeEval1_QosNotMet2();
		enterSequence_main_region_QosMet1_QosNotMet2_default();
	}
	
	private void effect_main_region_SafeEval1_QosNotMet2_tr2() {
		exitSequence_main_region_SafeEval1_QosNotMet2();
		enterSequence_main_region_QosNotMet1_QosNotMet2_default();
	}
	
	private void effect_main_region_SafeEval1_QosNotMet2_tr3() {
		exitSequence_main_region_SafeEval1_QosNotMet2();
		enterSequence_main_region_SafeEval1_QosNotMet2_default();
	}
	
	private void effect_main_region_QosMet1_SafeEval2_tr0() {
		exitSequence_main_region_QosMet1_SafeEval2();
		enterSequence_main_region_QosMet1_QosMet2_default();
	}
	
	private void effect_main_region_QosMet1_SafeEval2_tr1() {
		exitSequence_main_region_QosMet1_SafeEval2();
		enterSequence_main_region_QosMet1_QosNotMet2_default();
	}
	
	private void effect_main_region_QosMet1_SafeEval2_tr2() {
		exitSequence_main_region_QosMet1_SafeEval2();
		enterSequence_main_region_QosNotMet1_SafeEval2_default();
	}
	
	private void effect_main_region_QosMet1_SafeEval2_tr3() {
		exitSequence_main_region_QosMet1_SafeEval2();
		enterSequence_main_region_QosMet1_SafeEval2_default();
	}
	
	private void effect_main_region_QosNotMet1_SafeEval2_tr0() {
		exitSequence_main_region_QosNotMet1_SafeEval2();
		enterSequence_main_region_QosMet1_SafeEval2_default();
	}
	
	private void effect_main_region_QosNotMet1_SafeEval2_tr1() {
		exitSequence_main_region_QosNotMet1_SafeEval2();
		enterSequence_main_region_QosNotMet1_QosMet2_default();
	}
	
	private void effect_main_region_QosNotMet1_SafeEval2_tr2() {
		exitSequence_main_region_QosNotMet1_SafeEval2();
		enterSequence_main_region_QosNotMet1_QosNotMet2_default();
	}
	
	private void effect_main_region_QosNotMet1_SafeEval2_tr3() {
		exitSequence_main_region_QosNotMet1_SafeEval2();
		enterSequence_main_region_QosNotMet1_SafeEval2_default();
	}
	
	private void effect_main_region_SafeEval1_SafeEval2_tr0() {
		exitSequence_main_region_SafeEval1_SafeEval2();
		enterSequence_main_region_QosNotMet1_SafeEval2_default();
	}
	
	private void effect_main_region_SafeEval1_SafeEval2_tr1() {
		exitSequence_main_region_SafeEval1_SafeEval2();
		enterSequence_main_region_QosMet1_SafeEval2_default();
	}
	
	private void effect_main_region_SafeEval1_SafeEval2_tr2() {
		exitSequence_main_region_SafeEval1_SafeEval2();
		enterSequence_main_region_SafeEval1_QosNotMet2_default();
	}
	
	private void effect_main_region_SafeEval1_SafeEval2_tr3() {
		exitSequence_main_region_SafeEval1_SafeEval2();
		enterSequence_main_region_SafeEval1_QosMet2_default();
	}
	
	private void effect_main_region_SwitchGains_tr0() {
		exitSequence_main_region_SwitchGains();
		enterSequence_main_region_PowerCap_default();
	}
	
	private void effect_main_region_SwitchGains_tr1() {
		exitSequence_main_region_SwitchGains();
		enterSequence_main_region_SafeEval1_SafeEval2_default();
	}
	
	private void effect_main_region_QosMet1_QosNotMet2_tr0() {
		exitSequence_main_region_QosMet1_QosNotMet2();
		enterSequence_main_region_SwitchGains_default();
	}
	
	private void effect_main_region_QosMet1_QosNotMet2_tr1() {
		exitSequence_main_region_QosMet1_QosNotMet2();
		enterSequence_main_region_QosMet1_QosMet2_default();
	}
	
	private void effect_main_region_QosMet1_QosNotMet2_tr2() {
		exitSequence_main_region_QosMet1_QosNotMet2();
		enterSequence_main_region_QosNotMet1_QosNotMet2_default();
	}
	
	private void effect_main_region_QosMet1_QosNotMet2_tr3() {
		exitSequence_main_region_QosMet1_QosNotMet2();
		enterSequence_main_region_QosMet1_QosNotMet2_default();
	}
	
	private void effect_main_region_QosMet1_QosNotMet2_tr4() {
		exitSequence_main_region_QosMet1_QosNotMet2();
		enterSequence_main_region_QosMet1_QosNotMet2_default();
	}
	
	private void effect_main_region_QosNotMet1_QosMet2_tr0() {
		exitSequence_main_region_QosNotMet1_QosMet2();
		enterSequence_main_region_SwitchGains_default();
	}
	
	private void effect_main_region_QosNotMet1_QosMet2_tr1() {
		exitSequence_main_region_QosNotMet1_QosMet2();
		enterSequence_main_region_QosMet1_QosMet2_default();
	}
	
	private void effect_main_region_QosNotMet1_QosMet2_tr2() {
		exitSequence_main_region_QosNotMet1_QosMet2();
		enterSequence_main_region_QosNotMet1_QosNotMet2_default();
	}
	
	private void effect_main_region_QosNotMet1_QosMet2_tr3() {
		exitSequence_main_region_QosNotMet1_QosMet2();
		enterSequence_main_region_QosNotMet1_QosMet2_default();
	}
	
	private void effect_main_region_QosNotMet1_QosMet2_tr4() {
		exitSequence_main_region_QosNotMet1_QosMet2();
		enterSequence_main_region_QosNotMet1_QosMet2_default();
	}
	
	private void effect_main_region_QosNotMet1_QosNotMet2_tr0() {
		exitSequence_main_region_QosNotMet1_QosNotMet2();
		enterSequence_main_region_SwitchGains_default();
	}
	
	private void effect_main_region_QosNotMet1_QosNotMet2_tr1() {
		exitSequence_main_region_QosNotMet1_QosNotMet2();
		enterSequence_main_region_QosMet1_QosNotMet2_default();
	}
	
	private void effect_main_region_QosNotMet1_QosNotMet2_tr2() {
		exitSequence_main_region_QosNotMet1_QosNotMet2();
		enterSequence_main_region_QosNotMet1_QosMet2_default();
	}
	
	private void effect_main_region_QosNotMet1_QosNotMet2_tr3() {
		exitSequence_main_region_QosNotMet1_QosNotMet2();
		enterSequence_main_region_QosNotMet1_QosNotMet2_default();
	}
	
	private void effect_main_region_QosNotMet1_QosNotMet2_tr4() {
		exitSequence_main_region_QosNotMet1_QosNotMet2();
		enterSequence_main_region_QosNotMet1_QosNotMet2_default();
	}
	
	/* 'default' enter sequence for state QosMet1_QosMet2 */
	private void enterSequence_main_region_QosMet1_QosMet2_default() {
		nextStateIndex = 0;
		stateVector[0] = State.main_region_QosMet1_QosMet2;
	}
	
	/* 'default' enter sequence for state DangerPower */
	private void enterSequence_main_region_DangerPower_default() {
		nextStateIndex = 0;
		stateVector[0] = State.main_region_DangerPower;
	}
	
	/* 'default' enter sequence for state PowerCap */
	private void enterSequence_main_region_PowerCap_default() {
		nextStateIndex = 0;
		stateVector[0] = State.main_region_PowerCap;
	}
	
	/* 'default' enter sequence for state SafeEval1_QosMet2 */
	private void enterSequence_main_region_SafeEval1_QosMet2_default() {
		nextStateIndex = 0;
		stateVector[0] = State.main_region_SafeEval1_QosMet2;
	}
	
	/* 'default' enter sequence for state SafeEval1_QosNotMet2 */
	private void enterSequence_main_region_SafeEval1_QosNotMet2_default() {
		nextStateIndex = 0;
		stateVector[0] = State.main_region_SafeEval1_QosNotMet2;
	}
	
	/* 'default' enter sequence for state QosMet1_SafeEval2 */
	private void enterSequence_main_region_QosMet1_SafeEval2_default() {
		nextStateIndex = 0;
		stateVector[0] = State.main_region_QosMet1_SafeEval2;
	}
	
	/* 'default' enter sequence for state QosNotMet1_SafeEval2 */
	private void enterSequence_main_region_QosNotMet1_SafeEval2_default() {
		nextStateIndex = 0;
		stateVector[0] = State.main_region_QosNotMet1_SafeEval2;
	}
	
	/* 'default' enter sequence for state SafeEval1_SafeEval2 */
	private void enterSequence_main_region_SafeEval1_SafeEval2_default() {
		nextStateIndex = 0;
		stateVector[0] = State.main_region_SafeEval1_SafeEval2;
	}
	
	/* 'default' enter sequence for state SwitchGains */
	private void enterSequence_main_region_SwitchGains_default() {
		nextStateIndex = 0;
		stateVector[0] = State.main_region_SwitchGains;
	}
	
	/* 'default' enter sequence for state QosMet1_QosNotMet2 */
	private void enterSequence_main_region_QosMet1_QosNotMet2_default() {
		nextStateIndex = 0;
		stateVector[0] = State.main_region_QosMet1_QosNotMet2;
	}
	
	/* 'default' enter sequence for state QosNotMet1_QosMet2 */
	private void enterSequence_main_region_QosNotMet1_QosMet2_default() {
		nextStateIndex = 0;
		stateVector[0] = State.main_region_QosNotMet1_QosMet2;
	}
	
	/* 'default' enter sequence for state QosNotMet1_QosNotMet2 */
	private void enterSequence_main_region_QosNotMet1_QosNotMet2_default() {
		nextStateIndex = 0;
		stateVector[0] = State.main_region_QosNotMet1_QosNotMet2;
	}
	
	/* 'default' enter sequence for region main region */
	private void enterSequence_main_region_default() {
		react_main_region__entry_Default();
	}
	
	/* Default exit sequence for state QosMet1_QosMet2 */
	private void exitSequence_main_region_QosMet1_QosMet2() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state DangerPower */
	private void exitSequence_main_region_DangerPower() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state PowerCap */
	private void exitSequence_main_region_PowerCap() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state SafeEval1_QosMet2 */
	private void exitSequence_main_region_SafeEval1_QosMet2() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state SafeEval1_QosNotMet2 */
	private void exitSequence_main_region_SafeEval1_QosNotMet2() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state QosMet1_SafeEval2 */
	private void exitSequence_main_region_QosMet1_SafeEval2() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state QosNotMet1_SafeEval2 */
	private void exitSequence_main_region_QosNotMet1_SafeEval2() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state SafeEval1_SafeEval2 */
	private void exitSequence_main_region_SafeEval1_SafeEval2() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state SwitchGains */
	private void exitSequence_main_region_SwitchGains() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state QosMet1_QosNotMet2 */
	private void exitSequence_main_region_QosMet1_QosNotMet2() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state QosNotMet1_QosMet2 */
	private void exitSequence_main_region_QosNotMet1_QosMet2() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for state QosNotMet1_QosNotMet2 */
	private void exitSequence_main_region_QosNotMet1_QosNotMet2() {
		nextStateIndex = 0;
		stateVector[0] = State.$NullState$;
	}
	
	/* Default exit sequence for region main region */
	private void exitSequence_main_region() {
		switch (stateVector[0]) {
		case main_region_QosMet1_QosMet2:
			exitSequence_main_region_QosMet1_QosMet2();
			break;
		case main_region_DangerPower:
			exitSequence_main_region_DangerPower();
			break;
		case main_region_PowerCap:
			exitSequence_main_region_PowerCap();
			break;
		case main_region_SafeEval1_QosMet2:
			exitSequence_main_region_SafeEval1_QosMet2();
			break;
		case main_region_SafeEval1_QosNotMet2:
			exitSequence_main_region_SafeEval1_QosNotMet2();
			break;
		case main_region_QosMet1_SafeEval2:
			exitSequence_main_region_QosMet1_SafeEval2();
			break;
		case main_region_QosNotMet1_SafeEval2:
			exitSequence_main_region_QosNotMet1_SafeEval2();
			break;
		case main_region_SafeEval1_SafeEval2:
			exitSequence_main_region_SafeEval1_SafeEval2();
			break;
		case main_region_SwitchGains:
			exitSequence_main_region_SwitchGains();
			break;
		case main_region_QosMet1_QosNotMet2:
			exitSequence_main_region_QosMet1_QosNotMet2();
			break;
		case main_region_QosNotMet1_QosMet2:
			exitSequence_main_region_QosNotMet1_QosMet2();
			break;
		case main_region_QosNotMet1_QosNotMet2:
			exitSequence_main_region_QosNotMet1_QosNotMet2();
			break;
		default:
			break;
		}
	}
	
	/* The reactions of state QosMet1_QosMet2. */
	private void react_main_region_QosMet1_QosMet2() {
		if (check_main_region_QosMet1_QosMet2_tr0_tr0()) {
			effect_main_region_QosMet1_QosMet2_tr0();
		} else {
			if (check_main_region_QosMet1_QosMet2_tr1_tr1()) {
				effect_main_region_QosMet1_QosMet2_tr1();
			} else {
				if (check_main_region_QosMet1_QosMet2_tr2_tr2()) {
					effect_main_region_QosMet1_QosMet2_tr2();
				} else {
					if (check_main_region_QosMet1_QosMet2_tr3_tr3()) {
						effect_main_region_QosMet1_QosMet2_tr3();
					} else {
						if (check_main_region_QosMet1_QosMet2_tr4_tr4()) {
							effect_main_region_QosMet1_QosMet2_tr4();
						}
					}
				}
			}
		}
	}
	
	/* The reactions of state DangerPower. */
	private void react_main_region_DangerPower() {
		if (check_main_region_DangerPower_tr0_tr0()) {
			effect_main_region_DangerPower_tr0();
		} else {
			if (check_main_region_DangerPower_tr1_tr1()) {
				effect_main_region_DangerPower_tr1();
			} else {
				if (check_main_region_DangerPower_tr2_tr2()) {
					effect_main_region_DangerPower_tr2();
				}
			}
		}
	}
	
	/* The reactions of state PowerCap. */
	private void react_main_region_PowerCap() {
		if (check_main_region_PowerCap_tr0_tr0()) {
			effect_main_region_PowerCap_tr0();
		} else {
			if (check_main_region_PowerCap_tr1_tr1()) {
				effect_main_region_PowerCap_tr1();
			} else {
				if (check_main_region_PowerCap_tr2_tr2()) {
					effect_main_region_PowerCap_tr2();
				} else {
					if (check_main_region_PowerCap_tr3_tr3()) {
						effect_main_region_PowerCap_tr3();
					}
				}
			}
		}
	}
	
	/* The reactions of state SafeEval1_QosMet2. */
	private void react_main_region_SafeEval1_QosMet2() {
		if (check_main_region_SafeEval1_QosMet2_tr0_tr0()) {
			effect_main_region_SafeEval1_QosMet2_tr0();
		} else {
			if (check_main_region_SafeEval1_QosMet2_tr1_tr1()) {
				effect_main_region_SafeEval1_QosMet2_tr1();
			} else {
				if (check_main_region_SafeEval1_QosMet2_tr2_tr2()) {
					effect_main_region_SafeEval1_QosMet2_tr2();
				} else {
					if (check_main_region_SafeEval1_QosMet2_tr3_tr3()) {
						effect_main_region_SafeEval1_QosMet2_tr3();
					}
				}
			}
		}
	}
	
	/* The reactions of state SafeEval1_QosNotMet2. */
	private void react_main_region_SafeEval1_QosNotMet2() {
		if (check_main_region_SafeEval1_QosNotMet2_tr0_tr0()) {
			effect_main_region_SafeEval1_QosNotMet2_tr0();
		} else {
			if (check_main_region_SafeEval1_QosNotMet2_tr1_tr1()) {
				effect_main_region_SafeEval1_QosNotMet2_tr1();
			} else {
				if (check_main_region_SafeEval1_QosNotMet2_tr2_tr2()) {
					effect_main_region_SafeEval1_QosNotMet2_tr2();
				} else {
					if (check_main_region_SafeEval1_QosNotMet2_tr3_tr3()) {
						effect_main_region_SafeEval1_QosNotMet2_tr3();
					}
				}
			}
		}
	}
	
	/* The reactions of state QosMet1_SafeEval2. */
	private void react_main_region_QosMet1_SafeEval2() {
		if (check_main_region_QosMet1_SafeEval2_tr0_tr0()) {
			effect_main_region_QosMet1_SafeEval2_tr0();
		} else {
			if (check_main_region_QosMet1_SafeEval2_tr1_tr1()) {
				effect_main_region_QosMet1_SafeEval2_tr1();
			} else {
				if (check_main_region_QosMet1_SafeEval2_tr2_tr2()) {
					effect_main_region_QosMet1_SafeEval2_tr2();
				} else {
					if (check_main_region_QosMet1_SafeEval2_tr3_tr3()) {
						effect_main_region_QosMet1_SafeEval2_tr3();
					}
				}
			}
		}
	}
	
	/* The reactions of state QosNotMet1_SafeEval2. */
	private void react_main_region_QosNotMet1_SafeEval2() {
		if (check_main_region_QosNotMet1_SafeEval2_tr0_tr0()) {
			effect_main_region_QosNotMet1_SafeEval2_tr0();
		} else {
			if (check_main_region_QosNotMet1_SafeEval2_tr1_tr1()) {
				effect_main_region_QosNotMet1_SafeEval2_tr1();
			} else {
				if (check_main_region_QosNotMet1_SafeEval2_tr2_tr2()) {
					effect_main_region_QosNotMet1_SafeEval2_tr2();
				} else {
					if (check_main_region_QosNotMet1_SafeEval2_tr3_tr3()) {
						effect_main_region_QosNotMet1_SafeEval2_tr3();
					}
				}
			}
		}
	}
	
	/* The reactions of state SafeEval1_SafeEval2. */
	private void react_main_region_SafeEval1_SafeEval2() {
		if (check_main_region_SafeEval1_SafeEval2_tr0_tr0()) {
			effect_main_region_SafeEval1_SafeEval2_tr0();
		} else {
			if (check_main_region_SafeEval1_SafeEval2_tr1_tr1()) {
				effect_main_region_SafeEval1_SafeEval2_tr1();
			} else {
				if (check_main_region_SafeEval1_SafeEval2_tr2_tr2()) {
					effect_main_region_SafeEval1_SafeEval2_tr2();
				} else {
					if (check_main_region_SafeEval1_SafeEval2_tr3_tr3()) {
						effect_main_region_SafeEval1_SafeEval2_tr3();
					}
				}
			}
		}
	}
	
	/* The reactions of state SwitchGains. */
	private void react_main_region_SwitchGains() {
		if (check_main_region_SwitchGains_tr0_tr0()) {
			effect_main_region_SwitchGains_tr0();
		} else {
			if (check_main_region_SwitchGains_tr1_tr1()) {
				effect_main_region_SwitchGains_tr1();
			}
		}
	}
	
	/* The reactions of state QosMet1_QosNotMet2. */
	private void react_main_region_QosMet1_QosNotMet2() {
		if (check_main_region_QosMet1_QosNotMet2_tr0_tr0()) {
			effect_main_region_QosMet1_QosNotMet2_tr0();
		} else {
			if (check_main_region_QosMet1_QosNotMet2_tr1_tr1()) {
				effect_main_region_QosMet1_QosNotMet2_tr1();
			} else {
				if (check_main_region_QosMet1_QosNotMet2_tr2_tr2()) {
					effect_main_region_QosMet1_QosNotMet2_tr2();
				} else {
					if (check_main_region_QosMet1_QosNotMet2_tr3_tr3()) {
						effect_main_region_QosMet1_QosNotMet2_tr3();
					} else {
						if (check_main_region_QosMet1_QosNotMet2_tr4_tr4()) {
							effect_main_region_QosMet1_QosNotMet2_tr4();
						}
					}
				}
			}
		}
	}
	
	/* The reactions of state QosNotMet1_QosMet2. */
	private void react_main_region_QosNotMet1_QosMet2() {
		if (check_main_region_QosNotMet1_QosMet2_tr0_tr0()) {
			effect_main_region_QosNotMet1_QosMet2_tr0();
		} else {
			if (check_main_region_QosNotMet1_QosMet2_tr1_tr1()) {
				effect_main_region_QosNotMet1_QosMet2_tr1();
			} else {
				if (check_main_region_QosNotMet1_QosMet2_tr2_tr2()) {
					effect_main_region_QosNotMet1_QosMet2_tr2();
				} else {
					if (check_main_region_QosNotMet1_QosMet2_tr3_tr3()) {
						effect_main_region_QosNotMet1_QosMet2_tr3();
					} else {
						if (check_main_region_QosNotMet1_QosMet2_tr4_tr4()) {
							effect_main_region_QosNotMet1_QosMet2_tr4();
						}
					}
				}
			}
		}
	}
	
	/* The reactions of state QosNotMet1_QosNotMet2. */
	private void react_main_region_QosNotMet1_QosNotMet2() {
		if (check_main_region_QosNotMet1_QosNotMet2_tr0_tr0()) {
			effect_main_region_QosNotMet1_QosNotMet2_tr0();
		} else {
			if (check_main_region_QosNotMet1_QosNotMet2_tr1_tr1()) {
				effect_main_region_QosNotMet1_QosNotMet2_tr1();
			} else {
				if (check_main_region_QosNotMet1_QosNotMet2_tr2_tr2()) {
					effect_main_region_QosNotMet1_QosNotMet2_tr2();
				} else {
					if (check_main_region_QosNotMet1_QosNotMet2_tr3_tr3()) {
						effect_main_region_QosNotMet1_QosNotMet2_tr3();
					} else {
						if (check_main_region_QosNotMet1_QosNotMet2_tr4_tr4()) {
							effect_main_region_QosNotMet1_QosNotMet2_tr4();
						}
					}
				}
			}
		}
	}
	
	/* Default react sequence for initial entry  */
	private void react_main_region__entry_Default() {
		enterSequence_main_region_QosMet1_QosMet2_default();
	}
	
	public void runCycle() {
		if (!initialized)
			throw new IllegalStateException(
					"The state machine needs to be initialized first by calling the init() function.");
		clearOutEvents();
		for (nextStateIndex = 0; nextStateIndex < stateVector.length; nextStateIndex++) {
			switch (stateVector[nextStateIndex]) {
			case main_region_QosMet1_QosMet2:
				react_main_region_QosMet1_QosMet2();
				break;
			case main_region_DangerPower:
				react_main_region_DangerPower();
				break;
			case main_region_PowerCap:
				react_main_region_PowerCap();
				break;
			case main_region_SafeEval1_QosMet2:
				react_main_region_SafeEval1_QosMet2();
				break;
			case main_region_SafeEval1_QosNotMet2:
				react_main_region_SafeEval1_QosNotMet2();
				break;
			case main_region_QosMet1_SafeEval2:
				react_main_region_QosMet1_SafeEval2();
				break;
			case main_region_QosNotMet1_SafeEval2:
				react_main_region_QosNotMet1_SafeEval2();
				break;
			case main_region_SafeEval1_SafeEval2:
				react_main_region_SafeEval1_SafeEval2();
				break;
			case main_region_SwitchGains:
				react_main_region_SwitchGains();
				break;
			case main_region_QosMet1_QosNotMet2:
				react_main_region_QosMet1_QosNotMet2();
				break;
			case main_region_QosNotMet1_QosMet2:
				react_main_region_QosNotMet1_QosMet2();
				break;
			case main_region_QosNotMet1_QosNotMet2:
				react_main_region_QosNotMet1_QosNotMet2();
				break;
			default:
				// $NullState$
			}
		}
		clearEvents();
	}
}
