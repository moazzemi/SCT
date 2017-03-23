
#ifndef SIMPLE_H_
#define SIMPLE_H_

#include "..\src\sc_types.h"
#include "StatemachineInterface.h"

/*! \file Header of the state machine 'simple'.
*/

class Simple : public StatemachineInterface
{
	
	public:
		
		Simple();
		
		~Simple();
		
		/*! Enumeration of all states */ 
		typedef enum
		{
			main_region_QoS,
			main_region_SwitchGains,
			Simple_last_state
		} SimpleStates;
		
		//! Inner class for system interface scope.
		class SCI_System
		{
			
			public:
				/*! Gets the value of the variable 'gains' that is defined in the interface scope 'system'. */
				sc_boolean get_gains();
				
				/*! Sets the value of the variable 'gains' that is defined in the interface scope 'system'. */
				void set_gains(sc_boolean value);
				
				
			private:
				friend class Simple;
				sc_boolean gains;
		};
				
		
		/*! Returns an instance of the interface class 'SCI_System'. */
		SCI_System* getSCI_System();
		
		//! Inner class for power interface scope.
		class SCI_Power
		{
			
			public:
				/*! Raises the in event 'critical' that is defined in the interface scope 'power'. */
				void raise_critical();
				
				/*! Raises the in event 'notCritical' that is defined in the interface scope 'power'. */
				void raise_notCritical();
				
				
			private:
				friend class Simple;
				sc_boolean critical_raised;
				sc_boolean notCritical_raised;
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
		sc_boolean isStateActive(SimpleStates state);
	
	private:
	
	
		//! the maximum number of orthogonal states defines the dimension of the state configuration vector.
		static const sc_integer maxOrthogonalStates = 1;
		
		
		SimpleStates stateConfVector[maxOrthogonalStates];
		
		sc_ushort stateConfVectorPosition;
		
		SCI_System ifaceSystem;
		SCI_Power ifacePower;
		
		// prototypes of all internal functions
		
		sc_boolean check_main_region_QoS_tr0_tr0();
		sc_boolean check_main_region_SwitchGains_tr0_tr0();
		void effect_main_region_QoS_tr0();
		void effect_main_region_SwitchGains_tr0();
		void enact_main_region_QoS();
		void enact_main_region_SwitchGains();
		void enseq_main_region_QoS_default();
		void enseq_main_region_SwitchGains_default();
		void enseq_main_region_default();
		void exseq_main_region_QoS();
		void exseq_main_region_SwitchGains();
		void exseq_main_region();
		void react_main_region_QoS();
		void react_main_region_SwitchGains();
		void react_main_region__entry_Default();
		void clearInEvents();
		void clearOutEvents();
		
};
#endif /* SIMPLE_H_ */
