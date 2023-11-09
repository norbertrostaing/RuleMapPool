/*
 ==============================================================================

 MainComponentMenuBar.cpp
 Created: 25 Mar 2016 6:02:02pm
 Author:  Martin Hermant

 ==============================================================================
 */
 #include "MainComponent.h"
// #include "UserInputManager.h"
// #include "Definitions/Assistant/Assistant.h"

namespace RuleMapPoolCommandId
{
	static const int showAbout = 0x60000;
	static const int gotoWebsite = 0x60001;
	static const int gotoDiscord = 0x60002;
	static const int gotoDocs = 0x60003;
	static const int postGithubIssue = 0x60004;
	static const int donate = 0x60005;
	static const int sponsor = 0x60055;
	static const int showWelcome = 0x60006;
	static const int gotoChangelog = 0x60007;

	static const int guideStart = 0x300; //up to 0x300 +100
	static const int exitGuide = 0x399; 
	static const int goToCommunityModules = 0x500;
	static const int reloadCustomModules = 0x501;
	static const int exportSelection = 0x800;
	static const int importSelection = 0x801;

	//static const int keyBackspace = 0x60100;
	static const int keyClear = 0x60101;
	static const int keyEnter = 0x60102;
	static const int keyThru = 0x60103;
	static const int keyBackspace = 0x60104;
	static const int keyPlus = 0x60105;
	static const int keyMinus = 0x60106;

	static const int keyRecord = 0x60201;
	static const int keyEdit = 0x60202;
	static const int keyCopy = 0x60203;
	static const int keyDelete = 0x60204;

	static const int keyFixture = 0x60301;
	static const int keyGroup = 0x60302;
	static const int keyPreset = 0x60303;
	static const int keyCuelist = 0x60304;
	static const int keyCue = 0x60305;
	static const int keyEffect = 0x60306;
	static const int keyCarousel = 0x60307;
	static const int keyMapper= 0x60308;
	static const int keyAssistant = 0x60309;

	static const int keyHighlight = 0x60320;
	static const int keyBlind = 0x60321;

	static const int key1 = 0x60401;
	static const int key2 = 0x60402;
	static const int key3 = 0x60403;
	static const int key4 = 0x60404;
	static const int key5 = 0x60405;
	static const int key6 = 0x60406;
	static const int key7 = 0x60407;
	static const int key8 = 0x60408;
	static const int key9 = 0x60409;
	static const int key0 = 0x60410;



}

void MainContentComponent::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) 
{
	if (commandID >= RuleMapPoolCommandId::guideStart && commandID < RuleMapPoolCommandId::guideStart + 99)
	{
		// result.setInfo(Guider::getInstance()->getGuideName(commandID - RuleMapPoolCommandId::guideStart), "", "Guides", result.readOnlyInKeyEditor);
		return;
	}

	switch (commandID)
	{
	case RuleMapPoolCommandId::showAbout:
		result.setInfo("About...", "", "General", result.readOnlyInKeyEditor);
		break;

	case RuleMapPoolCommandId::showWelcome:
		result.setInfo("Show Welcome Screen...", "", "General", result.readOnlyInKeyEditor);
		break;

	case RuleMapPoolCommandId::donate:
		result.setInfo("Be cool and donate", "", "General", result.readOnlyInKeyEditor);
		break;

	case RuleMapPoolCommandId::sponsor:
		result.setInfo("Be even cooler and sponsor !", "", "General", result.readOnlyInKeyEditor);
		break;

	case RuleMapPoolCommandId::gotoWebsite:
		result.setInfo("Go to website", "", "Help", result.readOnlyInKeyEditor);
		break;

	case RuleMapPoolCommandId::gotoDiscord:
		result.setInfo("Go to Discord", "", "Help", result.readOnlyInKeyEditor);
		break;

	case RuleMapPoolCommandId::gotoDocs:
		result.setInfo("Go to the Amazing Documentation", "", "Help", result.readOnlyInKeyEditor);
		break;

	case RuleMapPoolCommandId::gotoChangelog:
		result.setInfo("See the changelog", "", "Help", result.readOnlyInKeyEditor);
		break;


	case RuleMapPoolCommandId::postGithubIssue:
		result.setInfo("Post an issue on github", "", "Help", result.readOnlyInKeyEditor);
		break;

	case RuleMapPoolCommandId::goToCommunityModules:
		result.setInfo("Community Modules Manager", "", "General", result.readOnlyInKeyEditor);
		break;

	case RuleMapPoolCommandId::reloadCustomModules:
		result.setInfo("Reload Custom Modules", "", "General", result.readOnlyInKeyEditor);
		break;

	case RuleMapPoolCommandId::exitGuide:
		result.setInfo("Exit current guide", "", "Guides", result.readOnlyInKeyEditor);
		result.addDefaultKeypress(KeyPress::escapeKey, ModifierKeys::noModifiers);
		// result.setActive(Guider::getInstance()->guide != nullptr);
		break;

	case RuleMapPoolCommandId::exportSelection:
		result.setInfo("Export Selection", "This will export the current selection as *.mochi file that can be later imported", "File", result.readOnlyInKeyEditor);
		result.addDefaultKeypress(KeyPress::createFromDescription("s").getKeyCode(), ModifierKeys::altModifier);
		result.setActive(InspectableSelectionManager::mainSelectionManager->currentInspectables.size() > 0);
		break;

	case RuleMapPoolCommandId::importSelection:
		result.setInfo("Import...", "This will import a *.mochi file and add it to the current project", "File", result.readOnlyInKeyEditor);
		result.addDefaultKeypress(KeyPress::createFromDescription("o").getKeyCode(), ModifierKeys::altModifier);
		break;



	/*
	case RuleMapPoolCommandId::keyBackspace:
		result.setInfo("backspace", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("backspace").getKeyCode(), ModifierKeys::ctrlModifier);
		break;

	case RuleMapPoolCommandId::keyClear:
		result.setInfo("Clear", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("backspace").getKeyCode(), ModifierKeys::shiftModifier);
		break;

	case RuleMapPoolCommandId::keyEnter:
		result.setInfo("Enter", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("return").getKeyCode(), ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::keyThru:
		result.setInfo("Thru", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("t").getKeyCode(), ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::keyPlus:
		result.setInfo("Plus +", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("+").getKeyCode(), ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::keyMinus:
		result.setInfo("Minus -", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("-").getKeyCode(), ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::keyRecord:
		result.setInfo("Record", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("r").getKeyCode(), ModifierKeys::noModifiers);
		result.addDefaultKeypress(KeyPress::createFromDescription("r").getKeyCode(), ModifierKeys::altModifier);
		break;

	case RuleMapPoolCommandId::keyEdit:
		result.setInfo("Edit", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("e").getKeyCode(), ModifierKeys::altModifier);
		break;

	case RuleMapPoolCommandId::keyCopy:
		result.setInfo("Copy", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("c").getKeyCode(), ModifierKeys::altModifier);
		break;

	case RuleMapPoolCommandId::keyDelete:
		result.setInfo("Delete", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("d").getKeyCode(), ModifierKeys::altModifier);
		break;




	case RuleMapPoolCommandId::keyFixture:
		result.setInfo("Fixture", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("f").getKeyCode(), ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::keyGroup:
		result.setInfo("Group", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("g").getKeyCode(), ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::keyPreset:
		result.setInfo("Preset", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("p").getKeyCode(), ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::keyCuelist:
		result.setInfo("Cuelist", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("l").getKeyCode(), ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::keyCue:
		result.setInfo("Cue", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("q").getKeyCode(), ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::keyEffect:
		result.setInfo("Effect", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("e").getKeyCode(), ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::keyCarousel:
		result.setInfo("Carousel", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("c").getKeyCode(), ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::keyMapper:
		result.setInfo("Mapper", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("m").getKeyCode(), ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::keyAssistant:
		result.setInfo("Assistant", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("a").getKeyCode(), ModifierKeys::noModifiers);
		break;


	case RuleMapPoolCommandId::keyHighlight:
		result.setInfo("Hightlight", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("h").getKeyCode(), ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::keyBlind:
		result.setInfo("Blind", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("b").getKeyCode(), ModifierKeys::noModifiers);
		break;





	case RuleMapPoolCommandId::key1:
		result.setInfo("Key 1", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("1").getKeyCode(), ModifierKeys::noModifiers);
		result.addDefaultKeypress(KeyPress::numberPad1, ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::key2:
		result.setInfo("Key 2", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("2").getKeyCode(), ModifierKeys::noModifiers);
		result.addDefaultKeypress(KeyPress::numberPad2, ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::key3:
		result.setInfo("Key 3", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("3").getKeyCode(), ModifierKeys::noModifiers);
		result.addDefaultKeypress(KeyPress::numberPad3, ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::key4:
		result.setInfo("Key 4", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("4").getKeyCode(), ModifierKeys::noModifiers);
		result.addDefaultKeypress(KeyPress::numberPad4, ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::key5:
		result.setInfo("Key 5", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("5").getKeyCode(), ModifierKeys::noModifiers);
		result.addDefaultKeypress(KeyPress::numberPad5, ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::key6:
		result.setInfo("Key 6", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("6").getKeyCode(), ModifierKeys::noModifiers);
		result.addDefaultKeypress(KeyPress::numberPad6, ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::key7:
		result.setInfo("Key 7", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("7").getKeyCode(), ModifierKeys::noModifiers);
		result.addDefaultKeypress(KeyPress::numberPad7, ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::key8:
		result.setInfo("Key 8", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("8").getKeyCode(), ModifierKeys::noModifiers);
		result.addDefaultKeypress(KeyPress::numberPad8, ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::key9:
		result.setInfo("Key 9", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("9").getKeyCode(), ModifierKeys::noModifiers);
		result.addDefaultKeypress(KeyPress::numberPad9, ModifierKeys::noModifiers);
		break;

	case RuleMapPoolCommandId::key0:
		result.setInfo("Key 0", "", "Direct Commands", 0);
		result.addDefaultKeypress(KeyPress::createFromDescription("0").getKeyCode(), ModifierKeys::noModifiers);
		result.addDefaultKeypress(KeyPress::numberPad0, ModifierKeys::noModifiers);
		break;

	case 0x40004: // bypass deleteing item with backspace 
		OrganicMainContentComponent::getCommandInfo(commandID, result);
		result.defaultKeypresses.remove(1);
		// result.defaultKeypresses.remove(0);
		break;

	*/
	default:
		OrganicMainContentComponent::getCommandInfo(commandID, result);
		break;
	}
}



void MainContentComponent::getAllCommands(Array<CommandID>& commands) {

	OrganicMainContentComponent::getAllCommands(commands);
	const CommandID ids[] = {

		// RuleMapPoolCommandId::showAbout,
		//RuleMapPoolCommandId::showWelcome,
		//RuleMapPoolCommandId::donate,
		//RuleMapPoolCommandId::sponsor,
		//RuleMapPoolCommandId::gotoWebsite,
		//RuleMapPoolCommandId::gotoDiscord,
		//RuleMapPoolCommandId::gotoDocs,
		//RuleMapPoolCommandId::gotoChangelog,
		//RuleMapPoolCommandId::postGithubIssue,
		RuleMapPoolCommandId::importSelection,
		RuleMapPoolCommandId::exportSelection
		//RuleMapPoolCommandId::goToCommunityModules,
		//RuleMapPoolCommandId::reloadCustomModules,
		//RuleMapPoolCommandId::exitGuide,


	};

	commands.addArray(ids, numElementsInArray(ids));
	//for (int i = 0; i < Guider::getInstance()->factory.defs.size(); ++i) commands.add(RuleMapPoolCommandId::guideStart + i);
}


PopupMenu MainContentComponent::getMenuForIndex(int topLevelMenuIndex, const String& menuName) 
{
	PopupMenu menu = OrganicMainContentComponent::getMenuForIndex(topLevelMenuIndex, menuName);

	if (menuName == "Help")
	{
		menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::showAbout);
		menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::showWelcome);
		menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::donate);
		menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::sponsor);
		menu.addSeparator();
		menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::gotoWebsite);
		menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::gotoDiscord);
		menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::gotoDocs);
		menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::gotoChangelog);
		menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::postGithubIssue);

	}else if (menuName == "Guides")
	{
	/*
		for (int i = 0; i < Guider::getInstance()->factory.defs.size(); ++i)
		{
			menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::guideStart + i);
		}

		menu.addSeparator();
		menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::exitGuide);
	*/
	}

	return menu;
}

void MainContentComponent::fillFileMenuInternal(PopupMenu & menu)
{
	menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::importSelection);
	menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::exportSelection);
	//menu.addSeparator();
	//menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::goToCommunityModules);
	//menu.addCommandItem(&getCommandManager(), RuleMapPoolCommandId::reloadCustomModules);
}

bool MainContentComponent::perform(const InvocationInfo& info)
{

	if (info.commandID >= RuleMapPoolCommandId::guideStart && info.commandID < RuleMapPoolCommandId::guideStart + 100)
	{
		// Guider::getInstance()->launchGuideAtIndex(info.commandID - RuleMapPoolCommandId::guideStart);
		return true;
	}

	switch (info.commandID)
	{


	case RuleMapPoolCommandId::showAbout:
	{
		// AboutWindow w;
		// DialogWindow::showModalDialog("About", &w, getTopLevelComponent(), Colours::transparentBlack, true);
	}
	break;

	case RuleMapPoolCommandId::showWelcome:
	{
		// WelcomeScreen w;
		// DialogWindow::showModalDialog("Welcome", &w, getTopLevelComponent(), Colours::black, true);
	}
	break;

	case RuleMapPoolCommandId::donate:
		URL("http://RuleMapPool.lighting/").launchInDefaultBrowser();
		break;

	case RuleMapPoolCommandId::sponsor:
		URL("http://RuleMapPool.lighting/").launchInDefaultBrowser();
		break;

	case RuleMapPoolCommandId::gotoWebsite:
		URL("http://RuleMapPool.lighting/").launchInDefaultBrowser();
		break;

	case RuleMapPoolCommandId::gotoDiscord:
		URL("https://discord.gg/wYNB3rK").launchInDefaultBrowser();
		break;

	case RuleMapPoolCommandId::gotoDocs:
		URL("https://benjamin.kuperberg.fr/chataigne/docs").launchInDefaultBrowser();
		break;

	case RuleMapPoolCommandId::gotoChangelog:
		URL("https://benjamin.kuperberg.fr/chataigne/releases/changelog.html").launchInDefaultBrowser();
		break;

	case RuleMapPoolCommandId::postGithubIssue:
		URL("http://github.com/benkuper/Chataigne/issues").launchInDefaultBrowser();
		break;


	case RuleMapPoolCommandId::goToCommunityModules:
		// CommunityModuleManager::getInstance()->selectThis();
		break;

	case RuleMapPoolCommandId::reloadCustomModules:
		// ModuleManager::getInstance()->factory->updateCustomModules();
		break;

	case RuleMapPoolCommandId::exitGuide:
		// Guider::getInstance()->setCurrentGuide(nullptr);
		break;

	case RuleMapPoolCommandId::exportSelection:
	{
		((RuleMapPoolEngine*)Engine::mainEngine)->exportSelection();
	}
	break;

	case RuleMapPoolCommandId::importSelection:
	{
		((RuleMapPoolEngine*)Engine::mainEngine)->importSelection();
	}
	break;
	/*
	case RuleMapPoolCommandId::keyAssistant: {Assistant::getInstance()->selectThis(); }break;

	case RuleMapPoolCommandId::keyFixture: {	UserInputManager::getInstance()->processInput("Fixture"); }break;
	case RuleMapPoolCommandId::keyGroup: {	UserInputManager::getInstance()->processInput("Group"); }break;
	case RuleMapPoolCommandId::keyPreset: {	UserInputManager::getInstance()->processInput("Preset"); }break;
	case RuleMapPoolCommandId::keyCuelist: {	UserInputManager::getInstance()->processInput("Cuelist"); }break;
	case RuleMapPoolCommandId::keyCue: {		UserInputManager::getInstance()->processInput("Cue"); }break;
	case RuleMapPoolCommandId::keyEffect: {	UserInputManager::getInstance()->processInput("Effect"); }break;
	case RuleMapPoolCommandId::keyCarousel: {	UserInputManager::getInstance()->processInput("Carousel"); }break;
	case RuleMapPoolCommandId::keyMapper: {	UserInputManager::getInstance()->processInput("Mapper"); }break;

	case RuleMapPoolCommandId::keyHighlight: {UserInputManager::getInstance()->toggleHightlight(); }break;
	case RuleMapPoolCommandId::keyBlind: {	UserInputManager::getInstance()->toggleBlind(); }break;

	case RuleMapPoolCommandId::keyClear: {	UserInputManager::getInstance()->processInput("Clear"); }break;
	case RuleMapPoolCommandId::keyBackspace: {UserInputManager::getInstance()->processInput("Backspace"); }break;
	case RuleMapPoolCommandId::keyEnter: {	UserInputManager::getInstance()->processInput("Enter"); }break;
	case RuleMapPoolCommandId::keyThru: {		UserInputManager::getInstance()->processInput("Thru"); }break;
	case RuleMapPoolCommandId::keyPlus: {		UserInputManager::getInstance()->processInput("+"); }break;
	case RuleMapPoolCommandId::keyMinus: {	UserInputManager::getInstance()->processInput("-"); }break;

	case RuleMapPoolCommandId::keyRecord: {	UserInputManager::getInstance()->processInput("record"); }break;
	case RuleMapPoolCommandId::keyCopy: {		UserInputManager::getInstance()->processInput("copy"); }break;
	case RuleMapPoolCommandId::keyEdit: {		UserInputManager::getInstance()->processInput("edit"); }break;
	case RuleMapPoolCommandId::keyDelete: {	UserInputManager::getInstance()->processInput("delete"); }break;

	case RuleMapPoolCommandId::key1: {		UserInputManager::getInstance()->processInput("1"); }break;
	case RuleMapPoolCommandId::key2: {		UserInputManager::getInstance()->processInput("2"); }break;
	case RuleMapPoolCommandId::key3: {		UserInputManager::getInstance()->processInput("3"); }break;
	case RuleMapPoolCommandId::key4: {		UserInputManager::getInstance()->processInput("4"); }break;
	case RuleMapPoolCommandId::key5: {		UserInputManager::getInstance()->processInput("5"); }break;
	case RuleMapPoolCommandId::key6: {		UserInputManager::getInstance()->processInput("6"); }break;
	case RuleMapPoolCommandId::key7: {		UserInputManager::getInstance()->processInput("7"); }break;
	case RuleMapPoolCommandId::key8: {		UserInputManager::getInstance()->processInput("8"); }break;
	case RuleMapPoolCommandId::key9: {		UserInputManager::getInstance()->processInput("9"); }break;
	case RuleMapPoolCommandId::key0: {		UserInputManager::getInstance()->processInput("0"); }break;
	*/

	default:
		return OrganicMainContentComponent::perform(info);
	}

	return true;
}

StringArray MainContentComponent::getMenuBarNames()
{
	StringArray names = OrganicMainContentComponent::getMenuBarNames();
	// names.add("Help");
	// names.add("Yataaa");
	return names;
}
