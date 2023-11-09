/*
 ==============================================================================

 ChataigneEngine.h
 Created: 2 Apr 2016 11:03:21am
 Author:  Martin Hermant

 ==============================================================================
 */


#pragma once

#include "JuceHeader.h"
 // #include "Module/ModuleIncludes.h"

class DMXChannelView;

struct geometryBreaks {
	String name;
	int breakNum;
	int offset;
};


class RuleMapPoolEngine :
	public Engine
{
public:
	RuleMapPoolEngine();
	~RuleMapPoolEngine();

	//Global Settings
	//ControllableContainer defaultBehaviors;

	void clearInternal() override;

	var getJSONData() override;
	void loadJSONDataInternalEngine(var data, ProgressTask* loadingTask) override;

	void childStructureChanged(ControllableContainer* cc) override;
	void controllableFeedbackUpdate(ControllableContainer* cc, Controllable* c) override;

	void handleAsyncUpdate() override;

	String getMinimumRequiredFileVersion() override;

	void importSelection();
	void exportSelection();
	void importMochi(var data);

	void parameterValueChanged(Parameter* p);

};

