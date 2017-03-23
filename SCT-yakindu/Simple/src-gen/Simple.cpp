
#include "Simple.h"
#include <string.h>

/*! \file Implementation of the state machine 'simple'
*/

Simple::Simple()
{
	
	
	stateConfVectorPosition = 0;
	
}

Simple::~Simple()
{
}


void Simple::init()
{
	for (int i = 0; i < maxOrthogonalStates; ++i)
		stateConfVector[i] = Simple_last_state;
	
	stateConfVectorPosition = 0;

	clearInEvents();
	clearOutEvents();
	
	/* Default init sequence for statechart simple */
	ifaceSystem.gains = false;
}

void Simple::enter()
{
	/* Default enter sequence for statechart simple */
	enseq_main_region_default();
}

void Simple::exit()
{
	/* Default exit sequence for statechart simple */
	exseq_main_region();
}

sc_boolean Simple::isActive()
{
	return stateConfVector[0] != Simple_last_state;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean Simple::isFinal()
{
   return false;}

void Simple::runCycle()
{
	
	clearOutEvents();
	
	for (stateConfVectorPosition = 0;
		stateConfVectorPosition < maxOrthogonalStates;
		stateConfVectorPosition++)
		{
			
		switch (stateConfVector[stateConfVectorPosition])
		{
		case main_region_QoS :
		{
			react_main_region_QoS();
			break;
		}
		case main_region_SwitchGains :
		{
			react_main_region_SwitchGains();
			break;
		}
		default:
			break;
		}
	}
	
	clearInEvents();
}

void Simple::clearInEvents()
{
	ifacePower.critical_raised = false;
	ifacePower.notCritical_raised = false;
}

void Simple::clearOutEvents()
{
}


sc_boolean Simple::isStateActive(SimpleStates state)
{
	switch (state)
	{
		case main_region_QoS : 
			return (sc_boolean) (stateConfVector[0] == main_region_QoS
			);
		case main_region_SwitchGains : 
			return (sc_boolean) (stateConfVector[0] == main_region_SwitchGains
			);
		default: return false;
	}
}

Simple::SCI_System* Simple::getSCI_System()
{
	return &ifaceSystem;
}


sc_boolean Simple::SCI_System::get_gains()
{
	return gains;
}

void Simple::SCI_System::set_gains(sc_boolean value)
{
	gains = value;
}

Simple::SCI_Power* Simple::getSCI_Power()
{
	return &ifacePower;
}

void Simple::SCI_Power::raise_critical()
{
	critical_raised = true;
}

void Simple::SCI_Power::raise_notCritical()
{
	notCritical_raised = true;
}



// implementations of all internal functions

sc_boolean Simple::check_main_region_QoS_tr0_tr0()
{
	return ifacePower.critical_raised;
}

sc_boolean Simple::check_main_region_SwitchGains_tr0_tr0()
{
	return ifacePower.notCritical_raised;
}

void Simple::effect_main_region_QoS_tr0()
{
	exseq_main_region_QoS();
	enseq_main_region_SwitchGains_default();
}

void Simple::effect_main_region_SwitchGains_tr0()
{
	exseq_main_region_SwitchGains();
	enseq_main_region_QoS_default();
}

/* Entry action for state 'QoS'. */
void Simple::enact_main_region_QoS()
{
	/* Entry action for state 'QoS'. */
	ifaceSystem.gains = 1;
}

/* Entry action for state 'SwitchGains'. */
void Simple::enact_main_region_SwitchGains()
{
	/* Entry action for state 'SwitchGains'. */
	ifaceSystem.gains = 0;
}

/* 'default' enter sequence for state QoS */
void Simple::enseq_main_region_QoS_default()
{
	/* 'default' enter sequence for state QoS */
	enact_main_region_QoS();
	stateConfVector[0] = main_region_QoS;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state SwitchGains */
void Simple::enseq_main_region_SwitchGains_default()
{
	/* 'default' enter sequence for state SwitchGains */
	enact_main_region_SwitchGains();
	stateConfVector[0] = main_region_SwitchGains;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
void Simple::enseq_main_region_default()
{
	/* 'default' enter sequence for region main region */
	react_main_region__entry_Default();
}

/* Default exit sequence for state QoS */
void Simple::exseq_main_region_QoS()
{
	/* Default exit sequence for state QoS */
	stateConfVector[0] = Simple_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state SwitchGains */
void Simple::exseq_main_region_SwitchGains()
{
	/* Default exit sequence for state SwitchGains */
	stateConfVector[0] = Simple_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for region main region */
void Simple::exseq_main_region()
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of simple.main_region) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case main_region_QoS :
		{
			exseq_main_region_QoS();
			break;
		}
		case main_region_SwitchGains :
		{
			exseq_main_region_SwitchGains();
			break;
		}
		default: break;
	}
}

/* The reactions of state QoS. */
void Simple::react_main_region_QoS()
{
	/* The reactions of state QoS. */
	if (check_main_region_QoS_tr0_tr0())
	{ 
		effect_main_region_QoS_tr0();
	} 
}

/* The reactions of state SwitchGains. */
void Simple::react_main_region_SwitchGains()
{
	/* The reactions of state SwitchGains. */
	if (check_main_region_SwitchGains_tr0_tr0())
	{ 
		effect_main_region_SwitchGains_tr0();
	} 
}

/* Default react sequence for initial entry  */
void Simple::react_main_region__entry_Default()
{
	/* Default react sequence for initial entry  */
	enseq_main_region_QoS_default();
}


