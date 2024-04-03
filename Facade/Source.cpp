#include <iostream>
using namespace std;

class Videocard
{
public:
	void Start()const {
		cout << "Videocard is starting the work...\n";
	}

	void CheckConnectionWithDisplay()const {
		cout << "Videocard is checking connection with display...\n";
	}

	void PrintDataAboutRAM()const {
		cout << "Videocard is printing data about RAM...\n";
	}

	void PrintInfoOpticalDiscDrive()const
	{
		cout << "Videocard is printing info about optical disc drive...\n";
	}

	void PrintDateAboutHDD()const {
		cout << "Videocard is printing data about HDD...\n";
	}

	void GoodbyeMessage()const
	{
		cout << "Videocard prints...GOODBYE\n";
	}
};

class RAM
{
public:
	void StartDevices()const {
		cout << "RAM is starting the work of devices...\n";
	}

	void AnalyseMemory()const
	{
		cout << "RAM is analysing the memory...\n";
	}

	void ClearMemory()const {
		cout << "RAM is clearing the memory...\n";
	}

	
	
};

class HDD
{
public:

	void Start()const {
		cout << "HDD is starting the work...\n";
	}

	void CheckBootSector()const {
		cout << "HDD is checking the boot sector...\n";
	}

	void Stop()const
	{
		cout << "HDD is stoping devices...\n";
	}
};

class PowerSupply
{
public:

	void SupplyPower()const {
		cout << "Power is supplying...\n";
	}

	void SupplyPowerVideocard()const {
		cout << "Power is supplying on the videocard...\n";
	}

	void SupplyPowerRAM()const {
		cout << "Power is supplying on the RAM...\n";
	}

	void SupplyPowerHDD()const {
		cout << "Power is supplying on the HDD...\n";
	}

	void SupplyPowerOpticalDiscDrive()const {
		cout << "Power is supplying on the Optical disc drive...\n";
	}

	void StopSupplyForVideocard()const
	{
		cout << "Power stopped supplying for the videocard\n";
	}

	void StopSupplyForRAM()const
	{
		cout << "Power stopped supplying for the RAM\n";
	}

	void StopSupplyForHDD()const
	{
		cout << "Power stopped supplying for the HDD\n";
	}

	void StopSupplyForOpticalDiscDrive()const
	{
		cout << "Power stooped supplying for the optical disc drive\n";
	}

	void Stop()const
	{
		cout << "Power supply stopped the work\n";
	}
};

class Sensors
{
public:
	void CheckVoltage()const
	{
		cout << "Sensors is checking voltage...\n";
	}

	void CheckTemperaturePS()const
	{
		cout << "Sensors is checking power supply temperature...\n";
	}

	void CheckTemperatureVideocard()const
	{
		cout << "Sensors is checking videocard temperature...\n";
	}

	void CheckTemperatureRAM()const
	{
		cout << "Sensors is checking RAM temperature...\n";
	}
	
	void CheckOverallTemperature()const
	{
		cout << "Sensors is checking all systems temperature...\n";
	}
};

class OpticalDiscDrive
{
public:
	void Start()const
	{
		cout << "Optical disc drive is starting the work...\n";
	}

	void CheckForDisc()const
	{
		cout << "Optical disc drive is checking for the disc...\n";
	}

	void ReturnToInitial()const {
		cout << "Optical disc drive is returning to the initial position...\n";
	}
};

class Facade
{
private:
	PowerSupply* ps;
	Videocard* videocard;
	HDD* hdd;
	RAM* ram;
	OpticalDiscDrive* odd;
	Sensors* sensors;
public:
	Facade(PowerSupply*ps,Videocard*videocard,HDD*hdd,RAM*ram,OpticalDiscDrive*odd,Sensors*sensors):ps(ps),videocard(videocard),hdd(hdd),ram(ram),odd(odd),sensors(sensors){}
	void Begin()const
	{
		ps->SupplyPower();
		sensors->CheckVoltage();
		sensors->CheckTemperaturePS();
		sensors->CheckTemperatureVideocard();
		ps->SupplyPowerVideocard();
		videocard->Start();
		videocard->CheckConnectionWithDisplay();
		sensors->CheckTemperatureRAM();
		ps->SupplyPowerRAM();
		ram->StartDevices();
		ram->AnalyseMemory();
		videocard->PrintDataAboutRAM();
		ps->SupplyPowerOpticalDiscDrive();
		odd->Start();
		odd->CheckForDisc();
		videocard->PrintInfoOpticalDiscDrive();
		ps->SupplyPowerHDD();
		hdd->Start();
		hdd->CheckBootSector();
		videocard->PrintDateAboutHDD();
		sensors->CheckOverallTemperature();
		cout << "\n\n";
	}

	void End()const
	{
		hdd->Stop();
		ram->ClearMemory();
		ram->AnalyseMemory();
		videocard->GoodbyeMessage();
		odd->ReturnToInitial();
		ps->StopSupplyForVideocard();
		ps->StopSupplyForRAM();
		ps->StopSupplyForOpticalDiscDrive();
		ps->StopSupplyForHDD();
		sensors->CheckVoltage();
		ps->Stop();
	}
};

int main()
{
	PowerSupply* ps=nullptr;
	Videocard* videocard = nullptr;
	HDD* hdd = nullptr;
	RAM* ram = nullptr;
	OpticalDiscDrive* odd = nullptr;
	Sensors* sensors = nullptr;
	Facade facade(ps, videocard, hdd, ram, odd, sensors);

	facade.Begin();

	facade.End();
}