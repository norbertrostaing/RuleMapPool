#pragma once

#include <JuceHeader.h>


#include "MainComponent.h"
#include "RuleMapPoolEngine.h"


ApplicationProperties& getAppProperties();
ApplicationCommandManager& getCommandManager();

class MainContentComponent;
class RuleMapPoolEngine;

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent :
    public OrganicMainContentComponent
    {
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent() override;
    
    void init() override;

    void getAllCommands(Array<CommandID>& commands) override;
    virtual void getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) override;
    virtual bool perform(const InvocationInfo& info) override;
    StringArray getMenuBarNames() override;
    virtual PopupMenu getMenuForIndex(int topLevelMenuIndex, const String& menuName) override;
    void fillFileMenuInternal(PopupMenu& menu) override;


private:
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
