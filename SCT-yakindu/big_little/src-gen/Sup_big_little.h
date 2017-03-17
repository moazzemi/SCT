
#ifndef SUP_BIG_LITTLE_H_
#define SUP_BIG_LITTLE_H_

#include "..\src\sc_types.h"
#include "StatemachineInterface.h"

/*! \file Header of the state machine 'sup_big_little'.
*/

class Sup_big_little : public StatemachineInterface
{
	
	public:
		
		Sup_big_little();
		
		~Sup_big_little();
		
		/*! Enumeration of all states */ 
		typedef enum
		{
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
			Sup_big_little_last_state
		} Sup_big_littleStates;
		
		//! Inner class for PC interface scope.
		class SCI_PC
		{
			
			public:
				/*! Raises the in event 'critical' that is defined in the interface scope 'PC'. */
				void raise_critical();
				
				/*! Raises the in event 'safeP' that is defined in the interface scope 'PC'. */
				void raise_safeP();
				
				/*! Raises the in event 'controlP' that is defined in the interface scope 'PC'. */
				void raise_controlP();
				
				/*! Raises the in event 'safeEval' that is defined in the interface scope 'PC'. */
				void raise_safeEval();
				
				
			private:
				friend class Sup_big_little;
				sc_boolean critical_raised;
				sc_boolean safeP_raised;
				sc_boolean controlP_raised;
				sc_boolean safeEval_raised;
		};
				
		
		/*! Returns an instance of the interface class 'SCI_PC'. */
		SCI_PC* getSCI_PC();
		
		//! Inner class for HR interface scope.
		class SCI_HR
		{
			
			public:
				/*! Raises the in event 'HRmet1' that is defined in the interface scope 'HR'. */
				void raise_hRmet1();
				
				/*! Raises the in event 'HRnotMet1' that is defined in the interface scope 'HR'. */
				void raise_hRnotMet1();
				
				/*! Raises the in event 'HRmet2' that is defined in the interface scope 'HR'. */
				void raise_hRmet2();
				
				/*! Raises the in event 'HRnotMet2' that is defined in the interface scope 'HR'. */
				void raise_hRnotMet2();
				
				
			private:
				friend class Sup_big_little;
				sc_boolean HRmet1_raised;
				sc_boolean HRnotMet1_raised;
				sc_boolean HRmet2_raised;
				sc_boolean HRnotMet2_raised;
		};
				
		
		/*! Returns an instance of the interface class 'SCI_HR'. */
		SCI_HR* getSCI_HR();
		
		//! Inner class for Safe interface scope.
		class SCI_Safe
		{
			
			public:
				/*! Raises the in event 'met1' that is defined in the interface scope 'Safe'. */
				void raise_met1();
				
				/*! Raises the in event 'notMet1' that is defined in the interface scope 'Safe'. */
				void raise_notMet1();
				
				/*! Raises the in event 'met2' that is defined in the interface scope 'Safe'. */
				void raise_met2();
				
				/*! Raises the in event 'notMet2' that is defined in the interface scope 'Safe'. */
				void raise_notMet2();
				
				
			private:
				friend class Sup_big_little;
				sc_boolean met1_raised;
				sc_boolean notMet1_raised;
				sc_boolean met2_raised;
				sc_boolean notMet2_raised;
		};
				
		
		/*! Returns an instance of the interface class 'SCI_Safe'. */
		SCI_Safe* getSCI_Safe();
		
		//! Inner class for Power interface scope.
		class SCI_Power
		{
			
			public:
				/*! Raises the in event 'decreaseP1' that is defined in the interface scope 'Power'. */
				void raise_decreaseP1();
				
				/*! Raises the in event 'decreaseP2' that is defined in the interface scope 'Power'. */
				void raise_decreaseP2();
				
				/*! Raises the in event 'increaseP1' that is defined in the interface scope 'Power'. */
				void raise_increaseP1();
				
				/*! Raises the in event 'increaseP2' that is defined in the interface scope 'Power'. */
				void raise_increaseP2();
				
				/*! Raises the in event 'decreaseCriticalP1' that is defined in the interface scope 'Power'. */
				void raise_decreaseCriticalP1();
				
				/*! Raises the in event 'decreaseCriticalP2' that is defined in the interface scope 'Power'. */
				void raise_decreaseCriticalP2();
				
				
			private:
				friend class Sup_big_little;
				sc_boolean decreaseP1_raised;
				sc_boolean decreaseP2_raised;
				sc_boolean increaseP1_raised;
				sc_boolean increaseP2_raised;
				sc_boolean decreaseCriticalP1_raised;
				sc_boolean decreaseCriticalP2_raised;
		};
				
		
		/*! Returns an instance of the interface class 'SCI_Power'. */
		SCI_Power* getSCI_Power();
		
		
		void init();
		
		void enter();
		
		void exit();
		
		void runCycle();
		
		/*!
		* Checks if the state machine is active (until 2.4.1 this method was used for states).
		* A state machine is active if it has been entered. It is inactive if it has not been entered at all or if it has been exited.
		*/
		sc_boolean isActive();
		
		
		/*!
		* Checks if all active states are final. 
		* If there are no active states then the state machine is considered being inactive. In this case this method returns false.
		*/
		sc_boolean isFinal();
		
		
		/*! Checks if the specified state is active (until 2.4.1 the used method for states was calles isActive()). */
		sc_boolean isStateActive(Sup_big_littleStates state);
	
	private:
	
	
		//! the maximum number of orthogonal states defines the dimension of the state configuration vector.
		static const sc_integer maxOrthogonalStates = 1;
		
		
		Sup_big_littleStates stateConfVector[maxOrthogonalStates];
		
		sc_ushort stateConfVectorPosition;
		
		SCI_PC ifacePC;
		SCI_HR ifaceHR;
		SCI_Safe ifaceSafe;
		SCI_Power ifacePower;
		
		// prototypes of all internal functions
		
		sc_boolean check_main_region_QosMet1_QosMet2_tr0_tr0();
		sc_boolean check_main_region_QosMet1_QosMet2_tr1_tr1();
		sc_boolean check_main_region_QosMet1_QosMet2_tr2_tr2();
		sc_boolean check_main_region_QosMet1_QosMet2_tr3_tr3();
		sc_boolean check_main_region_QosMet1_QosMet2_tr4_tr4();
		sc_boolean check_main_region_DangerPower_tr0_tr0();
		sc_boolean check_main_region_DangerPower_tr1_tr1();
		sc_boolean check_main_region_DangerPower_tr2_tr2();
		sc_boolean check_main_region_PowerCap_tr0_tr0();
		sc_boolean check_main_region_PowerCap_tr1_tr1();
		sc_boolean check_main_region_PowerCap_tr2_tr2();
		sc_boolean check_main_region_PowerCap_tr3_tr3();
		sc_boolean check_main_region_SafeEval1_QosMet2_tr0_tr0();
		sc_boolean check_main_region_SafeEval1_QosMet2_tr1_tr1();
		sc_boolean check_main_region_SafeEval1_QosMet2_tr2_tr2();
		sc_boolean check_main_region_SafeEval1_QosMet2_tr3_tr3();
		sc_boolean check_main_region_SafeEval1_QosNotMet2_tr0_tr0();
		sc_boolean check_main_region_SafeEval1_QosNotMet2_tr1_tr1();
		sc_boolean check_main_region_SafeEval1_QosNotMet2_tr2_tr2();
		sc_boolean check_main_region_SafeEval1_QosNotMet2_tr3_tr3();
		sc_boolean check_main_region_QosMet1_SafeEval2_tr0_tr0();
		sc_boolean check_main_region_QosMet1_SafeEval2_tr1_tr1();
		sc_boolean check_main_region_QosMet1_SafeEval2_tr2_tr2();
		sc_boolean check_main_region_QosMet1_SafeEval2_tr3_tr3();
		sc_boolean check_main_region_QosNotMet1_SafeEval2_tr0_tr0();
		sc_boolean check_main_region_QosNotMet1_SafeEval2_tr1_tr1();
		sc_boolean check_main_region_QosNotMet1_SafeEval2_tr2_tr2();
		sc_boolean check_main_region_QosNotMet1_SafeEval2_tr3_tr3();
		sc_boolean check_main_region_SafeEval1_SafeEval2_tr0_tr0();
		sc_boolean check_main_region_SafeEval1_SafeEval2_tr1_tr1();
		sc_boolean check_main_region_SafeEval1_SafeEval2_tr2_tr2();
		sc_boolean check_main_region_SafeEval1_SafeEval2_tr3_tr3();
		sc_boolean check_main_region_SwitchGains_tr0_tr0();
		sc_boolean check_main_region_SwitchGains_tr1_tr1();
		sc_boolean check_main_region_QosMet1_QosNotMet2_tr0_tr0();
		sc_boolean check_main_region_QosMet1_QosNotMet2_tr1_tr1();
		sc_boolean check_main_region_QosMet1_QosNotMet2_tr2_tr2();
		sc_boolean check_main_region_QosMet1_QosNotMet2_tr3_tr3();
		sc_boolean check_main_region_QosMet1_QosNotMet2_tr4_tr4();
		sc_boolean check_main_region_QosNotMet1_QosMet2_tr0_tr0();
		sc_boolean check_main_region_QosNotMet1_QosMet2_tr1_tr1();
		sc_boolean check_main_region_QosNotMet1_QosMet2_tr2_tr2();
		sc_boolean check_main_region_QosNotMet1_QosMet2_tr3_tr3();
		sc_boolean check_main_region_QosNotMet1_QosMet2_tr4_tr4();
		sc_boolean check_main_region_QosNotMet1_QosNotMet2_tr0_tr0();
		sc_boolean check_main_region_QosNotMet1_QosNotMet2_tr1_tr1();
		sc_boolean check_main_region_QosNotMet1_QosNotMet2_tr2_tr2();
		sc_boolean check_main_region_QosNotMet1_QosNotMet2_tr3_tr3();
		sc_boolean check_main_region_QosNotMet1_QosNotMet2_tr4_tr4();
		void effect_main_region_QosMet1_QosMet2_tr0();
		void effect_main_region_QosMet1_QosMet2_tr1();
		void effect_main_region_QosMet1_QosMet2_tr2();
		void effect_main_region_QosMet1_QosMet2_tr3();
		void effect_main_region_QosMet1_QosMet2_tr4();
		void effect_main_region_DangerPower_tr0();
		void effect_main_region_DangerPower_tr1();
		void effect_main_region_DangerPower_tr2();
		void effect_main_region_PowerCap_tr0();
		void effect_main_region_PowerCap_tr1();
		void effect_main_region_PowerCap_tr2();
		void effect_main_region_PowerCap_tr3();
		void effect_main_region_SafeEval1_QosMet2_tr0();
		void effect_main_region_SafeEval1_QosMet2_tr1();
		void effect_main_region_SafeEval1_QosMet2_tr2();
		void effect_main_region_SafeEval1_QosMet2_tr3();
		void effect_main_region_SafeEval1_QosNotMet2_tr0();
		void effect_main_region_SafeEval1_QosNotMet2_tr1();
		void effect_main_region_SafeEval1_QosNotMet2_tr2();
		void effect_main_region_SafeEval1_QosNotMet2_tr3();
		void effect_main_region_QosMet1_SafeEval2_tr0();
		void effect_main_region_QosMet1_SafeEval2_tr1();
		void effect_main_region_QosMet1_SafeEval2_tr2();
		void effect_main_region_QosMet1_SafeEval2_tr3();
		void effect_main_region_QosNotMet1_SafeEval2_tr0();
		void effect_main_region_QosNotMet1_SafeEval2_tr1();
		void effect_main_region_QosNotMet1_SafeEval2_tr2();
		void effect_main_region_QosNotMet1_SafeEval2_tr3();
		void effect_main_region_SafeEval1_SafeEval2_tr0();
		void effect_main_region_SafeEval1_SafeEval2_tr1();
		void effect_main_region_SafeEval1_SafeEval2_tr2();
		void effect_main_region_SafeEval1_SafeEval2_tr3();
		void effect_main_region_SwitchGains_tr0();
		void effect_main_region_SwitchGains_tr1();
		void effect_main_region_QosMet1_QosNotMet2_tr0();
		void effect_main_region_QosMet1_QosNotMet2_tr1();
		void effect_main_region_QosMet1_QosNotMet2_tr2();
		void effect_main_region_QosMet1_QosNotMet2_tr3();
		void effect_main_region_QosMet1_QosNotMet2_tr4();
		void effect_main_region_QosNotMet1_QosMet2_tr0();
		void effect_main_region_QosNotMet1_QosMet2_tr1();
		void effect_main_region_QosNotMet1_QosMet2_tr2();
		void effect_main_region_QosNotMet1_QosMet2_tr3();
		void effect_main_region_QosNotMet1_QosMet2_tr4();
		void effect_main_region_QosNotMet1_QosNotMet2_tr0();
		void effect_main_region_QosNotMet1_QosNotMet2_tr1();
		void effect_main_region_QosNotMet1_QosNotMet2_tr2();
		void effect_main_region_QosNotMet1_QosNotMet2_tr3();
		void effect_main_region_QosNotMet1_QosNotMet2_tr4();
		void enseq_main_region_QosMet1_QosMet2_default();
		void enseq_main_region_DangerPower_default();
		void enseq_main_region_PowerCap_default();
		void enseq_main_region_SafeEval1_QosMet2_default();
		void enseq_main_region_SafeEval1_QosNotMet2_default();
		void enseq_main_region_QosMet1_SafeEval2_default();
		void enseq_main_region_QosNotMet1_SafeEval2_default();
		void enseq_main_region_SafeEval1_SafeEval2_default();
		void enseq_main_region_SwitchGains_default();
		void enseq_main_region_QosMet1_QosNotMet2_default();
		void enseq_main_region_QosNotMet1_QosMet2_default();
		void enseq_main_region_QosNotMet1_QosNotMet2_default();
		void enseq_main_region_default();
		void exseq_main_region_QosMet1_QosMet2();
		void exseq_main_region_DangerPower();
		void exseq_main_region_PowerCap();
		void exseq_main_region_SafeEval1_QosMet2();
		void exseq_main_region_SafeEval1_QosNotMet2();
		void exseq_main_region_QosMet1_SafeEval2();
		void exseq_main_region_QosNotMet1_SafeEval2();
		void exseq_main_region_SafeEval1_SafeEval2();
		void exseq_main_region_SwitchGains();
		void exseq_main_region_QosMet1_QosNotMet2();
		void exseq_main_region_QosNotMet1_QosMet2();
		void exseq_main_region_QosNotMet1_QosNotMet2();
		void exseq_main_region();
		void react_main_region_QosMet1_QosMet2();
		void react_main_region_DangerPower();
		void react_main_region_PowerCap();
		void react_main_region_SafeEval1_QosMet2();
		void react_main_region_SafeEval1_QosNotMet2();
		void react_main_region_QosMet1_SafeEval2();
		void react_main_region_QosNotMet1_SafeEval2();
		void react_main_region_SafeEval1_SafeEval2();
		void react_main_region_SwitchGains();
		void react_main_region_QosMet1_QosNotMet2();
		void react_main_region_QosNotMet1_QosMet2();
		void react_main_region_QosNotMet1_QosNotMet2();
		void react_main_region__entry_Default();
		void clearInEvents();
		void clearOutEvents();
		
};
#endif /* SUP_BIG_LITTLE_H_ */
