
#include "Sup_big_little.h"
#include <string.h>

/*! \file Implementation of the state machine 'sup_big_little'
*/

Sup_big_little::Sup_big_little()
{
	
	
	stateConfVectorPosition = 0;
	
}

Sup_big_little::~Sup_big_little()
{
}


void Sup_big_little::init()
{
	for (int i = 0; i < maxOrthogonalStates; ++i)
		stateConfVector[i] = Sup_big_little_last_state;
	
	stateConfVectorPosition = 0;

	clearInEvents();
	clearOutEvents();
	
}

void Sup_big_little::enter()
{
	/* Default enter sequence for statechart sup_big_little */
	enseq_main_region_default();
}

void Sup_big_little::exit()
{
	/* Default exit sequence for statechart sup_big_little */
	exseq_main_region();
}

sc_boolean Sup_big_little::isActive()
{
	return stateConfVector[0] != Sup_big_little_last_state;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean Sup_big_little::isFinal()
{
   return false;}

void Sup_big_little::runCycle()
{
	
	clearOutEvents();
	
	for (stateConfVectorPosition = 0;
		stateConfVectorPosition < maxOrthogonalStates;
		stateConfVectorPosition++)
		{
			
		switch (stateConfVector[stateConfVectorPosition])
		{
		case main_region_QosMet1_QosMet2 :
		{
			react_main_region_QosMet1_QosMet2();
			break;
		}
		case main_region_DangerPower :
		{
			react_main_region_DangerPower();
			break;
		}
		case main_region_PowerCap :
		{
			react_main_region_PowerCap();
			break;
		}
		case main_region_SafeEval1_QosMet2 :
		{
			react_main_region_SafeEval1_QosMet2();
			break;
		}
		case main_region_SafeEval1_QosNotMet2 :
		{
			react_main_region_SafeEval1_QosNotMet2();
			break;
		}
		case main_region_QosMet1_SafeEval2 :
		{
			react_main_region_QosMet1_SafeEval2();
			break;
		}
		case main_region_QosNotMet1_SafeEval2 :
		{
			react_main_region_QosNotMet1_SafeEval2();
			break;
		}
		case main_region_SafeEval1_SafeEval2 :
		{
			react_main_region_SafeEval1_SafeEval2();
			break;
		}
		case main_region_SwitchGains :
		{
			react_main_region_SwitchGains();
			break;
		}
		case main_region_QosMet1_QosNotMet2 :
		{
			react_main_region_QosMet1_QosNotMet2();
			break;
		}
		case main_region_QosNotMet1_QosMet2 :
		{
			react_main_region_QosNotMet1_QosMet2();
			break;
		}
		case main_region_QosNotMet1_QosNotMet2 :
		{
			react_main_region_QosNotMet1_QosNotMet2();
			break;
		}
		default:
			break;
		}
	}
	
	clearInEvents();
}

void Sup_big_little::clearInEvents()
{
	ifacePC.critical_raised = false;
	ifacePC.safeP_raised = false;
	ifacePC.controlP_raised = false;
	ifacePC.safeEval_raised = false;
	ifaceHR.HRmet1_raised = false;
	ifaceHR.HRnotMet1_raised = false;
	ifaceHR.HRmet2_raised = false;
	ifaceHR.HRnotMet2_raised = false;
	ifaceSafe.met1_raised = false;
	ifaceSafe.notMet1_raised = false;
	ifaceSafe.met2_raised = false;
	ifaceSafe.notMet2_raised = false;
	ifacePower.decreaseP1_raised = false;
	ifacePower.decreaseP2_raised = false;
	ifacePower.increaseP1_raised = false;
	ifacePower.increaseP2_raised = false;
	ifacePower.decreaseCriticalP1_raised = false;
	ifacePower.decreaseCriticalP2_raised = false;
}

void Sup_big_little::clearOutEvents()
{
}


sc_boolean Sup_big_little::isStateActive(Sup_big_littleStates state)
{
	switch (state)
	{
		case main_region_QosMet1_QosMet2 : 
			return (sc_boolean) (stateConfVector[0] == main_region_QosMet1_QosMet2
			);
		case main_region_DangerPower : 
			return (sc_boolean) (stateConfVector[0] == main_region_DangerPower
			);
		case main_region_PowerCap : 
			return (sc_boolean) (stateConfVector[0] == main_region_PowerCap
			);
		case main_region_SafeEval1_QosMet2 : 
			return (sc_boolean) (stateConfVector[0] == main_region_SafeEval1_QosMet2
			);
		case main_region_SafeEval1_QosNotMet2 : 
			return (sc_boolean) (stateConfVector[0] == main_region_SafeEval1_QosNotMet2
			);
		case main_region_QosMet1_SafeEval2 : 
			return (sc_boolean) (stateConfVector[0] == main_region_QosMet1_SafeEval2
			);
		case main_region_QosNotMet1_SafeEval2 : 
			return (sc_boolean) (stateConfVector[0] == main_region_QosNotMet1_SafeEval2
			);
		case main_region_SafeEval1_SafeEval2 : 
			return (sc_boolean) (stateConfVector[0] == main_region_SafeEval1_SafeEval2
			);
		case main_region_SwitchGains : 
			return (sc_boolean) (stateConfVector[0] == main_region_SwitchGains
			);
		case main_region_QosMet1_QosNotMet2 : 
			return (sc_boolean) (stateConfVector[0] == main_region_QosMet1_QosNotMet2
			);
		case main_region_QosNotMet1_QosMet2 : 
			return (sc_boolean) (stateConfVector[0] == main_region_QosNotMet1_QosMet2
			);
		case main_region_QosNotMet1_QosNotMet2 : 
			return (sc_boolean) (stateConfVector[0] == main_region_QosNotMet1_QosNotMet2
			);
		default: return false;
	}
}

Sup_big_little::SCI_PC* Sup_big_little::getSCI_PC()
{
	return &ifacePC;
}

void Sup_big_little::SCI_PC::raise_critical()
{
	critical_raised = true;
}

void Sup_big_little::SCI_PC::raise_safeP()
{
	safeP_raised = true;
}

void Sup_big_little::SCI_PC::raise_controlP()
{
	controlP_raised = true;
}

void Sup_big_little::SCI_PC::raise_safeEval()
{
	safeEval_raised = true;
}


Sup_big_little::SCI_HR* Sup_big_little::getSCI_HR()
{
	return &ifaceHR;
}

void Sup_big_little::SCI_HR::raise_hRmet1()
{
	HRmet1_raised = true;
}

void Sup_big_little::SCI_HR::raise_hRnotMet1()
{
	HRnotMet1_raised = true;
}

void Sup_big_little::SCI_HR::raise_hRmet2()
{
	HRmet2_raised = true;
}

void Sup_big_little::SCI_HR::raise_hRnotMet2()
{
	HRnotMet2_raised = true;
}


Sup_big_little::SCI_Safe* Sup_big_little::getSCI_Safe()
{
	return &ifaceSafe;
}

void Sup_big_little::SCI_Safe::raise_met1()
{
	met1_raised = true;
}

void Sup_big_little::SCI_Safe::raise_notMet1()
{
	notMet1_raised = true;
}

void Sup_big_little::SCI_Safe::raise_met2()
{
	met2_raised = true;
}

void Sup_big_little::SCI_Safe::raise_notMet2()
{
	notMet2_raised = true;
}


Sup_big_little::SCI_Power* Sup_big_little::getSCI_Power()
{
	return &ifacePower;
}

void Sup_big_little::SCI_Power::raise_decreaseP1()
{
	decreaseP1_raised = true;
}

void Sup_big_little::SCI_Power::raise_decreaseP2()
{
	decreaseP2_raised = true;
}

void Sup_big_little::SCI_Power::raise_increaseP1()
{
	increaseP1_raised = true;
}

void Sup_big_little::SCI_Power::raise_increaseP2()
{
	increaseP2_raised = true;
}

void Sup_big_little::SCI_Power::raise_decreaseCriticalP1()
{
	decreaseCriticalP1_raised = true;
}

void Sup_big_little::SCI_Power::raise_decreaseCriticalP2()
{
	decreaseCriticalP2_raised = true;
}



// implementations of all internal functions

sc_boolean Sup_big_little::check_main_region_QosMet1_QosMet2_tr0_tr0()
{
	return ifacePC.critical_raised;
}

sc_boolean Sup_big_little::check_main_region_QosMet1_QosMet2_tr1_tr1()
{
	return ifaceHR.HRnotMet2_raised;
}

sc_boolean Sup_big_little::check_main_region_QosMet1_QosMet2_tr2_tr2()
{
	return ifaceHR.HRnotMet1_raised;
}

sc_boolean Sup_big_little::check_main_region_QosMet1_QosMet2_tr3_tr3()
{
	return ifacePower.decreaseP1_raised;
}

sc_boolean Sup_big_little::check_main_region_QosMet1_QosMet2_tr4_tr4()
{
	return ifacePower.decreaseP2_raised;
}

sc_boolean Sup_big_little::check_main_region_DangerPower_tr0_tr0()
{
	return ifacePC.safeP_raised;
}

sc_boolean Sup_big_little::check_main_region_DangerPower_tr1_tr1()
{
	return ifacePower.decreaseCriticalP1_raised;
}

sc_boolean Sup_big_little::check_main_region_DangerPower_tr2_tr2()
{
	return ifacePower.decreaseCriticalP2_raised;
}

sc_boolean Sup_big_little::check_main_region_PowerCap_tr0_tr0()
{
	return ifacePC.critical_raised;
}

sc_boolean Sup_big_little::check_main_region_PowerCap_tr1_tr1()
{
	return ifacePC.safeP_raised;
}

sc_boolean Sup_big_little::check_main_region_PowerCap_tr2_tr2()
{
	return ifacePower.decreaseCriticalP1_raised;
}

sc_boolean Sup_big_little::check_main_region_PowerCap_tr3_tr3()
{
	return ifacePower.decreaseCriticalP2_raised;
}

sc_boolean Sup_big_little::check_main_region_SafeEval1_QosMet2_tr0_tr0()
{
	return ifaceSafe.met1_raised;
}

sc_boolean Sup_big_little::check_main_region_SafeEval1_QosMet2_tr1_tr1()
{
	return ifaceHR.HRnotMet2_raised;
}

sc_boolean Sup_big_little::check_main_region_SafeEval1_QosMet2_tr2_tr2()
{
	return ifaceHR.HRnotMet1_raised;
}

sc_boolean Sup_big_little::check_main_region_SafeEval1_QosMet2_tr3_tr3()
{
	return ifacePower.decreaseP2_raised;
}

sc_boolean Sup_big_little::check_main_region_SafeEval1_QosNotMet2_tr0_tr0()
{
	return ifaceHR.HRmet2_raised;
}

sc_boolean Sup_big_little::check_main_region_SafeEval1_QosNotMet2_tr1_tr1()
{
	return ifaceSafe.met1_raised;
}

sc_boolean Sup_big_little::check_main_region_SafeEval1_QosNotMet2_tr2_tr2()
{
	return ifaceSafe.notMet1_raised;
}

sc_boolean Sup_big_little::check_main_region_SafeEval1_QosNotMet2_tr3_tr3()
{
	return ifacePower.increaseP2_raised;
}

sc_boolean Sup_big_little::check_main_region_QosMet1_SafeEval2_tr0_tr0()
{
	return ifaceSafe.met2_raised;
}

sc_boolean Sup_big_little::check_main_region_QosMet1_SafeEval2_tr1_tr1()
{
	return ifaceSafe.notMet2_raised;
}

sc_boolean Sup_big_little::check_main_region_QosMet1_SafeEval2_tr2_tr2()
{
	return ifaceHR.HRnotMet1_raised;
}

sc_boolean Sup_big_little::check_main_region_QosMet1_SafeEval2_tr3_tr3()
{
	return ifacePower.decreaseP1_raised;
}

sc_boolean Sup_big_little::check_main_region_QosNotMet1_SafeEval2_tr0_tr0()
{
	return ifaceHR.HRmet1_raised;
}

sc_boolean Sup_big_little::check_main_region_QosNotMet1_SafeEval2_tr1_tr1()
{
	return ifaceSafe.met2_raised;
}

sc_boolean Sup_big_little::check_main_region_QosNotMet1_SafeEval2_tr2_tr2()
{
	return ifaceSafe.notMet2_raised;
}

sc_boolean Sup_big_little::check_main_region_QosNotMet1_SafeEval2_tr3_tr3()
{
	return ifacePower.increaseP1_raised;
}

sc_boolean Sup_big_little::check_main_region_SafeEval1_SafeEval2_tr0_tr0()
{
	return ifaceHR.HRnotMet1_raised;
}

sc_boolean Sup_big_little::check_main_region_SafeEval1_SafeEval2_tr1_tr1()
{
	return ifaceHR.HRmet1_raised;
}

sc_boolean Sup_big_little::check_main_region_SafeEval1_SafeEval2_tr2_tr2()
{
	return ifaceHR.HRnotMet2_raised;
}

sc_boolean Sup_big_little::check_main_region_SafeEval1_SafeEval2_tr3_tr3()
{
	return ifaceHR.HRmet2_raised;
}

sc_boolean Sup_big_little::check_main_region_SwitchGains_tr0_tr0()
{
	return ifacePC.controlP_raised;
}

sc_boolean Sup_big_little::check_main_region_SwitchGains_tr1_tr1()
{
	return ifacePC.safeEval_raised;
}

sc_boolean Sup_big_little::check_main_region_QosMet1_QosNotMet2_tr0_tr0()
{
	return ifacePC.critical_raised;
}

sc_boolean Sup_big_little::check_main_region_QosMet1_QosNotMet2_tr1_tr1()
{
	return ifaceHR.HRmet2_raised;
}

sc_boolean Sup_big_little::check_main_region_QosMet1_QosNotMet2_tr2_tr2()
{
	return ifaceHR.HRnotMet1_raised;
}

sc_boolean Sup_big_little::check_main_region_QosMet1_QosNotMet2_tr3_tr3()
{
	return ifacePower.decreaseP1_raised;
}

sc_boolean Sup_big_little::check_main_region_QosMet1_QosNotMet2_tr4_tr4()
{
	return ifacePower.increaseP2_raised;
}

sc_boolean Sup_big_little::check_main_region_QosNotMet1_QosMet2_tr0_tr0()
{
	return ifacePC.critical_raised;
}

sc_boolean Sup_big_little::check_main_region_QosNotMet1_QosMet2_tr1_tr1()
{
	return ifaceHR.HRmet1_raised;
}

sc_boolean Sup_big_little::check_main_region_QosNotMet1_QosMet2_tr2_tr2()
{
	return ifaceHR.HRnotMet2_raised;
}

sc_boolean Sup_big_little::check_main_region_QosNotMet1_QosMet2_tr3_tr3()
{
	return ifacePower.increaseP1_raised;
}

sc_boolean Sup_big_little::check_main_region_QosNotMet1_QosMet2_tr4_tr4()
{
	return ifacePower.decreaseP1_raised;
}

sc_boolean Sup_big_little::check_main_region_QosNotMet1_QosNotMet2_tr0_tr0()
{
	return ifacePC.critical_raised;
}

sc_boolean Sup_big_little::check_main_region_QosNotMet1_QosNotMet2_tr1_tr1()
{
	return ifaceHR.HRmet1_raised;
}

sc_boolean Sup_big_little::check_main_region_QosNotMet1_QosNotMet2_tr2_tr2()
{
	return ifaceHR.HRmet2_raised;
}

sc_boolean Sup_big_little::check_main_region_QosNotMet1_QosNotMet2_tr3_tr3()
{
	return ifacePower.increaseP2_raised;
}

sc_boolean Sup_big_little::check_main_region_QosNotMet1_QosNotMet2_tr4_tr4()
{
	return ifacePower.increaseP1_raised;
}

void Sup_big_little::effect_main_region_QosMet1_QosMet2_tr0()
{
	exseq_main_region_QosMet1_QosMet2();
	enseq_main_region_SwitchGains_default();
}

void Sup_big_little::effect_main_region_QosMet1_QosMet2_tr1()
{
	exseq_main_region_QosMet1_QosMet2();
	enseq_main_region_QosMet1_QosNotMet2_default();
}

void Sup_big_little::effect_main_region_QosMet1_QosMet2_tr2()
{
	exseq_main_region_QosMet1_QosMet2();
	enseq_main_region_QosNotMet1_QosMet2_default();
}

void Sup_big_little::effect_main_region_QosMet1_QosMet2_tr3()
{
	exseq_main_region_QosMet1_QosMet2();
	enseq_main_region_QosMet1_QosMet2_default();
}

void Sup_big_little::effect_main_region_QosMet1_QosMet2_tr4()
{
	exseq_main_region_QosMet1_QosMet2();
	enseq_main_region_QosMet1_QosMet2_default();
}

void Sup_big_little::effect_main_region_DangerPower_tr0()
{
	exseq_main_region_DangerPower();
	enseq_main_region_PowerCap_default();
}

void Sup_big_little::effect_main_region_DangerPower_tr1()
{
	exseq_main_region_DangerPower();
	enseq_main_region_DangerPower_default();
}

void Sup_big_little::effect_main_region_DangerPower_tr2()
{
	exseq_main_region_DangerPower();
	enseq_main_region_DangerPower_default();
}

void Sup_big_little::effect_main_region_PowerCap_tr0()
{
	exseq_main_region_PowerCap();
	enseq_main_region_DangerPower_default();
}

void Sup_big_little::effect_main_region_PowerCap_tr1()
{
	exseq_main_region_PowerCap();
	enseq_main_region_SwitchGains_default();
}

void Sup_big_little::effect_main_region_PowerCap_tr2()
{
	exseq_main_region_PowerCap();
	enseq_main_region_PowerCap_default();
}

void Sup_big_little::effect_main_region_PowerCap_tr3()
{
	exseq_main_region_PowerCap();
	enseq_main_region_PowerCap_default();
}

void Sup_big_little::effect_main_region_SafeEval1_QosMet2_tr0()
{
	exseq_main_region_SafeEval1_QosMet2();
	enseq_main_region_QosMet1_QosMet2_default();
}

void Sup_big_little::effect_main_region_SafeEval1_QosMet2_tr1()
{
	exseq_main_region_SafeEval1_QosMet2();
	enseq_main_region_SafeEval1_QosNotMet2_default();
}

void Sup_big_little::effect_main_region_SafeEval1_QosMet2_tr2()
{
	exseq_main_region_SafeEval1_QosMet2();
	enseq_main_region_QosNotMet1_QosMet2_default();
}

void Sup_big_little::effect_main_region_SafeEval1_QosMet2_tr3()
{
	exseq_main_region_SafeEval1_QosMet2();
	enseq_main_region_SafeEval1_QosMet2_default();
}

void Sup_big_little::effect_main_region_SafeEval1_QosNotMet2_tr0()
{
	exseq_main_region_SafeEval1_QosNotMet2();
	enseq_main_region_SafeEval1_QosMet2_default();
}

void Sup_big_little::effect_main_region_SafeEval1_QosNotMet2_tr1()
{
	exseq_main_region_SafeEval1_QosNotMet2();
	enseq_main_region_QosMet1_QosNotMet2_default();
}

void Sup_big_little::effect_main_region_SafeEval1_QosNotMet2_tr2()
{
	exseq_main_region_SafeEval1_QosNotMet2();
	enseq_main_region_QosNotMet1_QosNotMet2_default();
}

void Sup_big_little::effect_main_region_SafeEval1_QosNotMet2_tr3()
{
	exseq_main_region_SafeEval1_QosNotMet2();
	enseq_main_region_SafeEval1_QosNotMet2_default();
}

void Sup_big_little::effect_main_region_QosMet1_SafeEval2_tr0()
{
	exseq_main_region_QosMet1_SafeEval2();
	enseq_main_region_QosMet1_QosMet2_default();
}

void Sup_big_little::effect_main_region_QosMet1_SafeEval2_tr1()
{
	exseq_main_region_QosMet1_SafeEval2();
	enseq_main_region_QosMet1_QosNotMet2_default();
}

void Sup_big_little::effect_main_region_QosMet1_SafeEval2_tr2()
{
	exseq_main_region_QosMet1_SafeEval2();
	enseq_main_region_QosNotMet1_SafeEval2_default();
}

void Sup_big_little::effect_main_region_QosMet1_SafeEval2_tr3()
{
	exseq_main_region_QosMet1_SafeEval2();
	enseq_main_region_QosMet1_SafeEval2_default();
}

void Sup_big_little::effect_main_region_QosNotMet1_SafeEval2_tr0()
{
	exseq_main_region_QosNotMet1_SafeEval2();
	enseq_main_region_QosMet1_SafeEval2_default();
}

void Sup_big_little::effect_main_region_QosNotMet1_SafeEval2_tr1()
{
	exseq_main_region_QosNotMet1_SafeEval2();
	enseq_main_region_QosNotMet1_QosMet2_default();
}

void Sup_big_little::effect_main_region_QosNotMet1_SafeEval2_tr2()
{
	exseq_main_region_QosNotMet1_SafeEval2();
	enseq_main_region_QosNotMet1_QosNotMet2_default();
}

void Sup_big_little::effect_main_region_QosNotMet1_SafeEval2_tr3()
{
	exseq_main_region_QosNotMet1_SafeEval2();
	enseq_main_region_QosNotMet1_SafeEval2_default();
}

void Sup_big_little::effect_main_region_SafeEval1_SafeEval2_tr0()
{
	exseq_main_region_SafeEval1_SafeEval2();
	enseq_main_region_QosNotMet1_SafeEval2_default();
}

void Sup_big_little::effect_main_region_SafeEval1_SafeEval2_tr1()
{
	exseq_main_region_SafeEval1_SafeEval2();
	enseq_main_region_QosMet1_SafeEval2_default();
}

void Sup_big_little::effect_main_region_SafeEval1_SafeEval2_tr2()
{
	exseq_main_region_SafeEval1_SafeEval2();
	enseq_main_region_SafeEval1_QosNotMet2_default();
}

void Sup_big_little::effect_main_region_SafeEval1_SafeEval2_tr3()
{
	exseq_main_region_SafeEval1_SafeEval2();
	enseq_main_region_SafeEval1_QosMet2_default();
}

void Sup_big_little::effect_main_region_SwitchGains_tr0()
{
	exseq_main_region_SwitchGains();
	enseq_main_region_PowerCap_default();
}

void Sup_big_little::effect_main_region_SwitchGains_tr1()
{
	exseq_main_region_SwitchGains();
	enseq_main_region_SafeEval1_SafeEval2_default();
}

void Sup_big_little::effect_main_region_QosMet1_QosNotMet2_tr0()
{
	exseq_main_region_QosMet1_QosNotMet2();
	enseq_main_region_SwitchGains_default();
}

void Sup_big_little::effect_main_region_QosMet1_QosNotMet2_tr1()
{
	exseq_main_region_QosMet1_QosNotMet2();
	enseq_main_region_QosMet1_QosMet2_default();
}

void Sup_big_little::effect_main_region_QosMet1_QosNotMet2_tr2()
{
	exseq_main_region_QosMet1_QosNotMet2();
	enseq_main_region_QosNotMet1_QosNotMet2_default();
}

void Sup_big_little::effect_main_region_QosMet1_QosNotMet2_tr3()
{
	exseq_main_region_QosMet1_QosNotMet2();
	enseq_main_region_QosMet1_QosNotMet2_default();
}

void Sup_big_little::effect_main_region_QosMet1_QosNotMet2_tr4()
{
	exseq_main_region_QosMet1_QosNotMet2();
	enseq_main_region_QosMet1_QosNotMet2_default();
}

void Sup_big_little::effect_main_region_QosNotMet1_QosMet2_tr0()
{
	exseq_main_region_QosNotMet1_QosMet2();
	enseq_main_region_SwitchGains_default();
}

void Sup_big_little::effect_main_region_QosNotMet1_QosMet2_tr1()
{
	exseq_main_region_QosNotMet1_QosMet2();
	enseq_main_region_QosMet1_QosMet2_default();
}

void Sup_big_little::effect_main_region_QosNotMet1_QosMet2_tr2()
{
	exseq_main_region_QosNotMet1_QosMet2();
	enseq_main_region_QosNotMet1_QosNotMet2_default();
}

void Sup_big_little::effect_main_region_QosNotMet1_QosMet2_tr3()
{
	exseq_main_region_QosNotMet1_QosMet2();
	enseq_main_region_QosNotMet1_QosMet2_default();
}

void Sup_big_little::effect_main_region_QosNotMet1_QosMet2_tr4()
{
	exseq_main_region_QosNotMet1_QosMet2();
	enseq_main_region_QosNotMet1_QosMet2_default();
}

void Sup_big_little::effect_main_region_QosNotMet1_QosNotMet2_tr0()
{
	exseq_main_region_QosNotMet1_QosNotMet2();
	enseq_main_region_SwitchGains_default();
}

void Sup_big_little::effect_main_region_QosNotMet1_QosNotMet2_tr1()
{
	exseq_main_region_QosNotMet1_QosNotMet2();
	enseq_main_region_QosMet1_QosNotMet2_default();
}

void Sup_big_little::effect_main_region_QosNotMet1_QosNotMet2_tr2()
{
	exseq_main_region_QosNotMet1_QosNotMet2();
	enseq_main_region_QosNotMet1_QosMet2_default();
}

void Sup_big_little::effect_main_region_QosNotMet1_QosNotMet2_tr3()
{
	exseq_main_region_QosNotMet1_QosNotMet2();
	enseq_main_region_QosNotMet1_QosNotMet2_default();
}

void Sup_big_little::effect_main_region_QosNotMet1_QosNotMet2_tr4()
{
	exseq_main_region_QosNotMet1_QosNotMet2();
	enseq_main_region_QosNotMet1_QosNotMet2_default();
}

/* 'default' enter sequence for state QosMet1_QosMet2 */
void Sup_big_little::enseq_main_region_QosMet1_QosMet2_default()
{
	/* 'default' enter sequence for state QosMet1_QosMet2 */
	stateConfVector[0] = main_region_QosMet1_QosMet2;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state DangerPower */
void Sup_big_little::enseq_main_region_DangerPower_default()
{
	/* 'default' enter sequence for state DangerPower */
	stateConfVector[0] = main_region_DangerPower;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state PowerCap */
void Sup_big_little::enseq_main_region_PowerCap_default()
{
	/* 'default' enter sequence for state PowerCap */
	stateConfVector[0] = main_region_PowerCap;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state SafeEval1_QosMet2 */
void Sup_big_little::enseq_main_region_SafeEval1_QosMet2_default()
{
	/* 'default' enter sequence for state SafeEval1_QosMet2 */
	stateConfVector[0] = main_region_SafeEval1_QosMet2;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state SafeEval1_QosNotMet2 */
void Sup_big_little::enseq_main_region_SafeEval1_QosNotMet2_default()
{
	/* 'default' enter sequence for state SafeEval1_QosNotMet2 */
	stateConfVector[0] = main_region_SafeEval1_QosNotMet2;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state QosMet1_SafeEval2 */
void Sup_big_little::enseq_main_region_QosMet1_SafeEval2_default()
{
	/* 'default' enter sequence for state QosMet1_SafeEval2 */
	stateConfVector[0] = main_region_QosMet1_SafeEval2;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state QosNotMet1_SafeEval2 */
void Sup_big_little::enseq_main_region_QosNotMet1_SafeEval2_default()
{
	/* 'default' enter sequence for state QosNotMet1_SafeEval2 */
	stateConfVector[0] = main_region_QosNotMet1_SafeEval2;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state SafeEval1_SafeEval2 */
void Sup_big_little::enseq_main_region_SafeEval1_SafeEval2_default()
{
	/* 'default' enter sequence for state SafeEval1_SafeEval2 */
	stateConfVector[0] = main_region_SafeEval1_SafeEval2;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state SwitchGains */
void Sup_big_little::enseq_main_region_SwitchGains_default()
{
	/* 'default' enter sequence for state SwitchGains */
	stateConfVector[0] = main_region_SwitchGains;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state QosMet1_QosNotMet2 */
void Sup_big_little::enseq_main_region_QosMet1_QosNotMet2_default()
{
	/* 'default' enter sequence for state QosMet1_QosNotMet2 */
	stateConfVector[0] = main_region_QosMet1_QosNotMet2;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state QosNotMet1_QosMet2 */
void Sup_big_little::enseq_main_region_QosNotMet1_QosMet2_default()
{
	/* 'default' enter sequence for state QosNotMet1_QosMet2 */
	stateConfVector[0] = main_region_QosNotMet1_QosMet2;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state QosNotMet1_QosNotMet2 */
void Sup_big_little::enseq_main_region_QosNotMet1_QosNotMet2_default()
{
	/* 'default' enter sequence for state QosNotMet1_QosNotMet2 */
	stateConfVector[0] = main_region_QosNotMet1_QosNotMet2;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
void Sup_big_little::enseq_main_region_default()
{
	/* 'default' enter sequence for region main region */
	react_main_region__entry_Default();
}

/* Default exit sequence for state QosMet1_QosMet2 */
void Sup_big_little::exseq_main_region_QosMet1_QosMet2()
{
	/* Default exit sequence for state QosMet1_QosMet2 */
	stateConfVector[0] = Sup_big_little_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state DangerPower */
void Sup_big_little::exseq_main_region_DangerPower()
{
	/* Default exit sequence for state DangerPower */
	stateConfVector[0] = Sup_big_little_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state PowerCap */
void Sup_big_little::exseq_main_region_PowerCap()
{
	/* Default exit sequence for state PowerCap */
	stateConfVector[0] = Sup_big_little_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state SafeEval1_QosMet2 */
void Sup_big_little::exseq_main_region_SafeEval1_QosMet2()
{
	/* Default exit sequence for state SafeEval1_QosMet2 */
	stateConfVector[0] = Sup_big_little_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state SafeEval1_QosNotMet2 */
void Sup_big_little::exseq_main_region_SafeEval1_QosNotMet2()
{
	/* Default exit sequence for state SafeEval1_QosNotMet2 */
	stateConfVector[0] = Sup_big_little_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state QosMet1_SafeEval2 */
void Sup_big_little::exseq_main_region_QosMet1_SafeEval2()
{
	/* Default exit sequence for state QosMet1_SafeEval2 */
	stateConfVector[0] = Sup_big_little_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state QosNotMet1_SafeEval2 */
void Sup_big_little::exseq_main_region_QosNotMet1_SafeEval2()
{
	/* Default exit sequence for state QosNotMet1_SafeEval2 */
	stateConfVector[0] = Sup_big_little_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state SafeEval1_SafeEval2 */
void Sup_big_little::exseq_main_region_SafeEval1_SafeEval2()
{
	/* Default exit sequence for state SafeEval1_SafeEval2 */
	stateConfVector[0] = Sup_big_little_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state SwitchGains */
void Sup_big_little::exseq_main_region_SwitchGains()
{
	/* Default exit sequence for state SwitchGains */
	stateConfVector[0] = Sup_big_little_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state QosMet1_QosNotMet2 */
void Sup_big_little::exseq_main_region_QosMet1_QosNotMet2()
{
	/* Default exit sequence for state QosMet1_QosNotMet2 */
	stateConfVector[0] = Sup_big_little_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state QosNotMet1_QosMet2 */
void Sup_big_little::exseq_main_region_QosNotMet1_QosMet2()
{
	/* Default exit sequence for state QosNotMet1_QosMet2 */
	stateConfVector[0] = Sup_big_little_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state QosNotMet1_QosNotMet2 */
void Sup_big_little::exseq_main_region_QosNotMet1_QosNotMet2()
{
	/* Default exit sequence for state QosNotMet1_QosNotMet2 */
	stateConfVector[0] = Sup_big_little_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for region main region */
void Sup_big_little::exseq_main_region()
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of sup_big_little.main_region) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case main_region_QosMet1_QosMet2 :
		{
			exseq_main_region_QosMet1_QosMet2();
			break;
		}
		case main_region_DangerPower :
		{
			exseq_main_region_DangerPower();
			break;
		}
		case main_region_PowerCap :
		{
			exseq_main_region_PowerCap();
			break;
		}
		case main_region_SafeEval1_QosMet2 :
		{
			exseq_main_region_SafeEval1_QosMet2();
			break;
		}
		case main_region_SafeEval1_QosNotMet2 :
		{
			exseq_main_region_SafeEval1_QosNotMet2();
			break;
		}
		case main_region_QosMet1_SafeEval2 :
		{
			exseq_main_region_QosMet1_SafeEval2();
			break;
		}
		case main_region_QosNotMet1_SafeEval2 :
		{
			exseq_main_region_QosNotMet1_SafeEval2();
			break;
		}
		case main_region_SafeEval1_SafeEval2 :
		{
			exseq_main_region_SafeEval1_SafeEval2();
			break;
		}
		case main_region_SwitchGains :
		{
			exseq_main_region_SwitchGains();
			break;
		}
		case main_region_QosMet1_QosNotMet2 :
		{
			exseq_main_region_QosMet1_QosNotMet2();
			break;
		}
		case main_region_QosNotMet1_QosMet2 :
		{
			exseq_main_region_QosNotMet1_QosMet2();
			break;
		}
		case main_region_QosNotMet1_QosNotMet2 :
		{
			exseq_main_region_QosNotMet1_QosNotMet2();
			break;
		}
		default: break;
	}
}

/* The reactions of state QosMet1_QosMet2. */
void Sup_big_little::react_main_region_QosMet1_QosMet2()
{
	/* The reactions of state QosMet1_QosMet2. */
	if (check_main_region_QosMet1_QosMet2_tr0_tr0())
	{ 
		effect_main_region_QosMet1_QosMet2_tr0();
	}  else
	{
		if (check_main_region_QosMet1_QosMet2_tr1_tr1())
		{ 
			effect_main_region_QosMet1_QosMet2_tr1();
		}  else
		{
			if (check_main_region_QosMet1_QosMet2_tr2_tr2())
			{ 
				effect_main_region_QosMet1_QosMet2_tr2();
			}  else
			{
				if (check_main_region_QosMet1_QosMet2_tr3_tr3())
				{ 
					effect_main_region_QosMet1_QosMet2_tr3();
				}  else
				{
					if (check_main_region_QosMet1_QosMet2_tr4_tr4())
					{ 
						effect_main_region_QosMet1_QosMet2_tr4();
					} 
				}
			}
		}
	}
}

/* The reactions of state DangerPower. */
void Sup_big_little::react_main_region_DangerPower()
{
	/* The reactions of state DangerPower. */
	if (check_main_region_DangerPower_tr0_tr0())
	{ 
		effect_main_region_DangerPower_tr0();
	}  else
	{
		if (check_main_region_DangerPower_tr1_tr1())
		{ 
			effect_main_region_DangerPower_tr1();
		}  else
		{
			if (check_main_region_DangerPower_tr2_tr2())
			{ 
				effect_main_region_DangerPower_tr2();
			} 
		}
	}
}

/* The reactions of state PowerCap. */
void Sup_big_little::react_main_region_PowerCap()
{
	/* The reactions of state PowerCap. */
	if (check_main_region_PowerCap_tr0_tr0())
	{ 
		effect_main_region_PowerCap_tr0();
	}  else
	{
		if (check_main_region_PowerCap_tr1_tr1())
		{ 
			effect_main_region_PowerCap_tr1();
		}  else
		{
			if (check_main_region_PowerCap_tr2_tr2())
			{ 
				effect_main_region_PowerCap_tr2();
			}  else
			{
				if (check_main_region_PowerCap_tr3_tr3())
				{ 
					effect_main_region_PowerCap_tr3();
				} 
			}
		}
	}
}

/* The reactions of state SafeEval1_QosMet2. */
void Sup_big_little::react_main_region_SafeEval1_QosMet2()
{
	/* The reactions of state SafeEval1_QosMet2. */
	if (check_main_region_SafeEval1_QosMet2_tr0_tr0())
	{ 
		effect_main_region_SafeEval1_QosMet2_tr0();
	}  else
	{
		if (check_main_region_SafeEval1_QosMet2_tr1_tr1())
		{ 
			effect_main_region_SafeEval1_QosMet2_tr1();
		}  else
		{
			if (check_main_region_SafeEval1_QosMet2_tr2_tr2())
			{ 
				effect_main_region_SafeEval1_QosMet2_tr2();
			}  else
			{
				if (check_main_region_SafeEval1_QosMet2_tr3_tr3())
				{ 
					effect_main_region_SafeEval1_QosMet2_tr3();
				} 
			}
		}
	}
}

/* The reactions of state SafeEval1_QosNotMet2. */
void Sup_big_little::react_main_region_SafeEval1_QosNotMet2()
{
	/* The reactions of state SafeEval1_QosNotMet2. */
	if (check_main_region_SafeEval1_QosNotMet2_tr0_tr0())
	{ 
		effect_main_region_SafeEval1_QosNotMet2_tr0();
	}  else
	{
		if (check_main_region_SafeEval1_QosNotMet2_tr1_tr1())
		{ 
			effect_main_region_SafeEval1_QosNotMet2_tr1();
		}  else
		{
			if (check_main_region_SafeEval1_QosNotMet2_tr2_tr2())
			{ 
				effect_main_region_SafeEval1_QosNotMet2_tr2();
			}  else
			{
				if (check_main_region_SafeEval1_QosNotMet2_tr3_tr3())
				{ 
					effect_main_region_SafeEval1_QosNotMet2_tr3();
				} 
			}
		}
	}
}

/* The reactions of state QosMet1_SafeEval2. */
void Sup_big_little::react_main_region_QosMet1_SafeEval2()
{
	/* The reactions of state QosMet1_SafeEval2. */
	if (check_main_region_QosMet1_SafeEval2_tr0_tr0())
	{ 
		effect_main_region_QosMet1_SafeEval2_tr0();
	}  else
	{
		if (check_main_region_QosMet1_SafeEval2_tr1_tr1())
		{ 
			effect_main_region_QosMet1_SafeEval2_tr1();
		}  else
		{
			if (check_main_region_QosMet1_SafeEval2_tr2_tr2())
			{ 
				effect_main_region_QosMet1_SafeEval2_tr2();
			}  else
			{
				if (check_main_region_QosMet1_SafeEval2_tr3_tr3())
				{ 
					effect_main_region_QosMet1_SafeEval2_tr3();
				} 
			}
		}
	}
}

/* The reactions of state QosNotMet1_SafeEval2. */
void Sup_big_little::react_main_region_QosNotMet1_SafeEval2()
{
	/* The reactions of state QosNotMet1_SafeEval2. */
	if (check_main_region_QosNotMet1_SafeEval2_tr0_tr0())
	{ 
		effect_main_region_QosNotMet1_SafeEval2_tr0();
	}  else
	{
		if (check_main_region_QosNotMet1_SafeEval2_tr1_tr1())
		{ 
			effect_main_region_QosNotMet1_SafeEval2_tr1();
		}  else
		{
			if (check_main_region_QosNotMet1_SafeEval2_tr2_tr2())
			{ 
				effect_main_region_QosNotMet1_SafeEval2_tr2();
			}  else
			{
				if (check_main_region_QosNotMet1_SafeEval2_tr3_tr3())
				{ 
					effect_main_region_QosNotMet1_SafeEval2_tr3();
				} 
			}
		}
	}
}

/* The reactions of state SafeEval1_SafeEval2. */
void Sup_big_little::react_main_region_SafeEval1_SafeEval2()
{
	/* The reactions of state SafeEval1_SafeEval2. */
	if (check_main_region_SafeEval1_SafeEval2_tr0_tr0())
	{ 
		effect_main_region_SafeEval1_SafeEval2_tr0();
	}  else
	{
		if (check_main_region_SafeEval1_SafeEval2_tr1_tr1())
		{ 
			effect_main_region_SafeEval1_SafeEval2_tr1();
		}  else
		{
			if (check_main_region_SafeEval1_SafeEval2_tr2_tr2())
			{ 
				effect_main_region_SafeEval1_SafeEval2_tr2();
			}  else
			{
				if (check_main_region_SafeEval1_SafeEval2_tr3_tr3())
				{ 
					effect_main_region_SafeEval1_SafeEval2_tr3();
				} 
			}
		}
	}
}

/* The reactions of state SwitchGains. */
void Sup_big_little::react_main_region_SwitchGains()
{
	/* The reactions of state SwitchGains. */
	if (check_main_region_SwitchGains_tr0_tr0())
	{ 
		effect_main_region_SwitchGains_tr0();
	}  else
	{
		if (check_main_region_SwitchGains_tr1_tr1())
		{ 
			effect_main_region_SwitchGains_tr1();
		} 
	}
}

/* The reactions of state QosMet1_QosNotMet2. */
void Sup_big_little::react_main_region_QosMet1_QosNotMet2()
{
	/* The reactions of state QosMet1_QosNotMet2. */
	if (check_main_region_QosMet1_QosNotMet2_tr0_tr0())
	{ 
		effect_main_region_QosMet1_QosNotMet2_tr0();
	}  else
	{
		if (check_main_region_QosMet1_QosNotMet2_tr1_tr1())
		{ 
			effect_main_region_QosMet1_QosNotMet2_tr1();
		}  else
		{
			if (check_main_region_QosMet1_QosNotMet2_tr2_tr2())
			{ 
				effect_main_region_QosMet1_QosNotMet2_tr2();
			}  else
			{
				if (check_main_region_QosMet1_QosNotMet2_tr3_tr3())
				{ 
					effect_main_region_QosMet1_QosNotMet2_tr3();
				}  else
				{
					if (check_main_region_QosMet1_QosNotMet2_tr4_tr4())
					{ 
						effect_main_region_QosMet1_QosNotMet2_tr4();
					} 
				}
			}
		}
	}
}

/* The reactions of state QosNotMet1_QosMet2. */
void Sup_big_little::react_main_region_QosNotMet1_QosMet2()
{
	/* The reactions of state QosNotMet1_QosMet2. */
	if (check_main_region_QosNotMet1_QosMet2_tr0_tr0())
	{ 
		effect_main_region_QosNotMet1_QosMet2_tr0();
	}  else
	{
		if (check_main_region_QosNotMet1_QosMet2_tr1_tr1())
		{ 
			effect_main_region_QosNotMet1_QosMet2_tr1();
		}  else
		{
			if (check_main_region_QosNotMet1_QosMet2_tr2_tr2())
			{ 
				effect_main_region_QosNotMet1_QosMet2_tr2();
			}  else
			{
				if (check_main_region_QosNotMet1_QosMet2_tr3_tr3())
				{ 
					effect_main_region_QosNotMet1_QosMet2_tr3();
				}  else
				{
					if (check_main_region_QosNotMet1_QosMet2_tr4_tr4())
					{ 
						effect_main_region_QosNotMet1_QosMet2_tr4();
					} 
				}
			}
		}
	}
}

/* The reactions of state QosNotMet1_QosNotMet2. */
void Sup_big_little::react_main_region_QosNotMet1_QosNotMet2()
{
	/* The reactions of state QosNotMet1_QosNotMet2. */
	if (check_main_region_QosNotMet1_QosNotMet2_tr0_tr0())
	{ 
		effect_main_region_QosNotMet1_QosNotMet2_tr0();
	}  else
	{
		if (check_main_region_QosNotMet1_QosNotMet2_tr1_tr1())
		{ 
			effect_main_region_QosNotMet1_QosNotMet2_tr1();
		}  else
		{
			if (check_main_region_QosNotMet1_QosNotMet2_tr2_tr2())
			{ 
				effect_main_region_QosNotMet1_QosNotMet2_tr2();
			}  else
			{
				if (check_main_region_QosNotMet1_QosNotMet2_tr3_tr3())
				{ 
					effect_main_region_QosNotMet1_QosNotMet2_tr3();
				}  else
				{
					if (check_main_region_QosNotMet1_QosNotMet2_tr4_tr4())
					{ 
						effect_main_region_QosNotMet1_QosNotMet2_tr4();
					} 
				}
			}
		}
	}
}

/* Default react sequence for initial entry  */
void Sup_big_little::react_main_region__entry_Default()
{
	/* Default react sequence for initial entry  */
	enseq_main_region_QosMet1_QosMet2_default();
}


