#include "Main.h"
#include "JuceHeader.h"
#include "RuleMapPoolEngine.h"
#include "MainComponent.h"

//==============================================================================

RuleMapPoolApplication::RuleMapPoolApplication() :
	OrganicApplication("RuleMapPool", true, ImageCache::getFromMemory(BinaryData::icon_png, BinaryData::icon_pngSize))
{
}


void RuleMapPoolApplication::initialiseInternal(const String &)
{
	engine.reset(new RuleMapPoolEngine());
	if(useWindow) mainComponent.reset(new MainContentComponent());

	//Call after engine init
	AppUpdater::getInstance()->setURLs("http://RuleMapPool.lighting/update.json", "http://RuleMapPool.lighting/installs/", "RuleMapPool");
	// HelpBox::getInstance()->helpURL = URL("http://benjamin.kuperberg.fr/chataigne/help/");

	//CrashDumpUploader::getInstance()->init("http://hazlab.fr/RuleMapPool/crash_report.php",ImageCache::getFromMemory(BinaryData::crash_png, BinaryData::crash_pngSize));

	// DashboardManager::getInstance()->setupDownloadURL("http://benjamin.kuperberg.fr/download/dashboard/dashboard.php?folder=dashboard");
	
	ShapeShifterManager::getInstance()->setDefaultFileData(BinaryData::default_rmplayout  );
	ShapeShifterManager::getInstance()->setLayoutInformations("rmplayout", "RuleMapPool/layouts");
}


void RuleMapPoolApplication::afterInit()
{
	//ANALYTICS
	if (mainWindow != nullptr)
	{
		
		// MainContentComponent* comp = (MainContentComponent*)mainComponent.get();
		// RuleMapPoolEngine* eng = (RuleMapPoolEngine*)engine.get();
		//RMPMenuBarComponent* menu = new RMPMenuBarComponent(comp, eng);
		// mainWindow->setMenuBarComponent(menu);
	}
	

}

void RuleMapPoolApplication::shutdown()
{   
	OrganicApplication::shutdown();
	AppUpdater::deleteInstance();
}

void RuleMapPoolApplication::handleCrashed()
{
	/*
	for (auto& m : ModuleManager::getInstance()->getItemsWithType<OSModule>())
	{
		m->crashedTrigger->trigger();
	}

	if (enableSendAnalytics->boolValue())
	{
		MatomoAnalytics::getInstance()->log(MatomoAnalytics::CRASH);
		while (MatomoAnalytics::getInstance()->isThreadRunning())
		{
			//wait until thread is done
		}
	}
	*/
	OrganicApplication::handleCrashed();
}
