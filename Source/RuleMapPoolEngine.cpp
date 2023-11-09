/*
 ==============================================================================

 Engine.cpp
 Created: 2 Apr 2016 11:03:21am
 Author:  Martin Hermant

 ==============================================================================
 */
#include "RuleMapPoolEngine.h"
#include "JuceHeader.h"

#include "Definitions/Screen/ScreenManager.h"

ControllableContainer* getAppSettings();

RuleMapPoolEngine::RuleMapPoolEngine() :
	Engine("RuleMapPool", ".olga")
	//defaultBehaviors("Test"),
	//ossiaFixture(nullptr)
{
	convertURL = "http://hazlab.fr/";
	
	//Communication
	// OSCRemoteControl::getInstance()->addRemoteControlListener(UserInputManager::getInstance());
	//init here
	Engine::mainEngine = this;
	RuleMapPoolEngine::mainEngine = this;

	GlobalSettings::getInstance()->altScaleFactor->setDefaultValue(0.002);

	addChildControllableContainer(ScreenManager::getInstance());

	// MIDIManager::getInstance(); //Trigger constructor, declare settings

	// getAppSettings()->addChildControllableContainer(&defaultBehaviors);
}

RuleMapPoolEngine::~RuleMapPoolEngine()
{
	//Application-end cleanup, nothing should be recreated after this
	//delete singletons here

	isClearing = true;

#if JUCE_WINDOWS
	//WindowsHooker::deleteInstance();
#endif

	// ZeroconfManager::deleteInstance();
	// CommunityModuleManager::deleteInstance();
	// ModuleRouterManager::deleteInstance();

	// ChataigneSequenceManager::deleteInstance();
	// StateManager::deleteInstance();
	// ModuleManager::deleteInstance();

	// MIDIManager::deleteInstance();
	// DMXManager::deleteInstance();
	// SerialManager::deleteInstance();
	// WiimoteManager::deleteInstance();

	// InputSystemManager::deleteInstance();
	// StreamDeckManager::deleteInstance();

	// ChataigneAssetManager::deleteInstance();

	// CVGroupManager::deleteInstance();

	// Guider::deleteInstance();
	ScreenManager::deleteInstance();
}


void RuleMapPoolEngine::clearInternal()
{
	//clear
	// StateManager::getInstance()->clear();
	// ChataigneSequenceManager::getInstance()->clear();

	// ModuleRouterManager::getInstance()->clear();
	// ModuleManager::getInstance()->clear();
	ScreenManager::getInstance()->clear();
}

var RuleMapPoolEngine::getJSONData()
{
	var data = Engine::getJSONData();

	//var mData = ModuleManager::getInstance()->getJSONData();
	//if (!mData.isVoid() && mData.getDynamicObject()->getProperties().size() > 0) data.getDynamicObject()->setProperty(ModuleManager::getInstance()->shortName, mData);

	var screenData = ScreenManager::getInstance()->getJSONData();
	if (!screenData.isVoid() && screenData.getDynamicObject()->getProperties().size() > 0) data.getDynamicObject()->setProperty(ScreenManager::getInstance()->shortName, screenData);

	return data;
}

void RuleMapPoolEngine::loadJSONDataInternalEngine(var data, ProgressTask* loadingTask)
{
	//ProgressTask* moduleTask = loadingTask->addTask("Modules");
	ProgressTask* screenTask = loadingTask->addTask("Screens");




	screenTask->start();
	ScreenManager::getInstance()->loadJSONData(data.getProperty(ScreenManager::getInstance()->shortName, var()));
	screenTask->setProgress(1);
	screenTask->end();


}

void RuleMapPoolEngine::childStructureChanged(ControllableContainer* cc)
{
	Engine::childStructureChanged(cc);
}

void RuleMapPoolEngine::controllableFeedbackUpdate(ControllableContainer* cc, Controllable* c)
{
	if (isClearing || isLoadingFile) return;
}

void RuleMapPoolEngine::handleAsyncUpdate()
{
	Engine::handleAsyncUpdate();
}

String RuleMapPoolEngine::getMinimumRequiredFileVersion()
{
	return "1.0.0";
}

void RuleMapPoolEngine::importSelection()
{
	const MessageManagerLock mmLock;
	FileChooser fc("Load some files", File::getCurrentWorkingDirectory(), "*.mochi");
	/*
	if (!fc.browseForMultipleFilesToOpen()) return;
	Array<File> f = fc.getResults();
	for (int i = 0; i < f.size(); i++) {
		if (f[i].hasFileExtension("mochi")) {
			importMochi(f[i]);
		}
	}
	*/
}

void RuleMapPoolEngine::importMochi(var data)
{
	if (!data.isObject()) return;

	ScreenManager::getInstance()->addItemsFromData(data.getProperty(ScreenManager::getInstance()->shortName, var()));
}

void RuleMapPoolEngine::exportSelection()
{
	var data(new DynamicObject());

	data.getDynamicObject()->setProperty(ScreenManager::getInstance()->shortName, ScreenManager::getInstance()->getExportSelectionData());

	String s = JSON::toString(data);
	
	/*
	FileChooser fc("Save a mochi", File::getCurrentWorkingDirectory(), "*.mochi");
	if (fc.browseForFileToSave(true))
	{
		File f = fc.getResult();
		f.replaceWithText(s);
	}
	*/
}

void RuleMapPoolEngine::parameterValueChanged(Parameter* p) {
	Engine::parameterValueChanged(p);
	/* if (p == panelScale) {
		InputPanel::getInstance()->resized();
	}
	*/

}
