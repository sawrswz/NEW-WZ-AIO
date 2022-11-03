#include "menu.h"
#include <sstream>
#include <iostream>


void SetCamo(int Class, int Weapon, int Camo)
{
	char context[255];
	char state[255];
	int navStringCount;
	char* navStrings[16]{};
	const char* mode = "";

	if (gameMode == 0)
	{
		mode = xorstr_("ddl/mp/rankedloadouts.ddl");
		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 3);
	}
	else if (gameMode == 1)
	{
		mode = xorstr_("ddl/mp/wzrankedloadouts.ddl");
		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 5);
	}



	__int64 ddl_file = Com_DDL_LoadAsset((__int64)mode);

	DDL_GetRootState((__int64)state, ddl_file);
	char buffer[200];
	memset(buffer, 0, 200);
	sprintf_s(buffer, xorstr_("squadMembers.loadouts.%i.weaponSetups.%i.camo"), Class, Weapon);
	ParseShit(buffer, (const char**)navStrings, 16, &navStringCount);
	if (DDL_MoveToPath((__int64*)&state, (__int64*)&state, navStringCount, (const char**)navStrings))
	{
		DDL_SetInt((__int64)state, (__int64)context, Camo);
	}

}


void SetName(int Class, char* Name)
{
	char context[255];
	char state[255];
	int navStringCount;
	char* navStrings[16]{};
	const char* mode = "";

	if (gameMode1 == 0)
	{
		mode = xorstr_("ddl/mp/rankedloadouts.ddl");
		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 3);
	}
	else if (gameMode1 == 1)
	{
		mode = xorstr_("ddl/mp/wzrankedloadouts.ddl");
		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 5);
	}



	__int64 ddl_file = Com_DDL_LoadAsset((__int64)mode);

	DDL_GetRootState((__int64)state, ddl_file);
	char buffer[200];
	memset(buffer, 0, 200);
	sprintf_s(buffer, xorstr_("squadMembers.loadouts.%i.name"), Class);
	ParseShit(buffer, (const char**)navStrings, 16, &navStringCount);
	if (DDL_MoveToPath((__int64*)&state, (__int64*)&state, navStringCount, (const char**)navStrings))
	{
		DDL_SetString((__int64)state, (__int64)context, Name);
	}

}

void CopyWeapon(int Class)
{
	char context[255];
	char state[255];
	char context2[255];
	char state2[255];
	int navStringCount;
	char* navStrings[16]{};
	int navStringCount2;
	char* navStrings2[16]{};
	const char* mode = "";
	int wep = 0;

	if (gameMode1 == 0)
	{
		mode = xorstr_("ddl/mp/rankedloadouts.ddl");
		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 3);
	}
	else if (gameMode1 == 1)
	{
		mode = xorstr_("ddl/mp/wzrankedloadouts.ddl");
		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 5);
	}

	__int64 ddl_file = Com_DDL_LoadAsset((__int64)mode);

	DDL_GetRootState((__int64)state, ddl_file);
	char buffer[200];
	memset(buffer, 0, 200);
	sprintf_s(buffer, xorstr_("squadMembers.loadouts.%i.weaponSetups.0.weapon"), Class);
	ParseShit(buffer, (const char**)navStrings, 16, &navStringCount);
	if (DDL_MoveToPath((__int64*)&state, (__int64*)&state, navStringCount, (const char**)navStrings))
	{
		wep = DDL_GetInt((__int64*)&state, (__int64*)&context);

	}
	if (gameMode1 == 0)
	{
		mode = xorstr_("ddl/mp/rankedloadouts.ddl");
		CL_PlayerData_GetDDLBuffer((__int64)context2, 0, 0, 3);
	}
	else if (gameMode1 == 1)
	{
		mode = xorstr_("ddl/mp/wzrankedloadouts.ddl");
		CL_PlayerData_GetDDLBuffer((__int64)context2, 0, 0, 5);
	}
	__int64 ddl_file2 = Com_DDL_LoadAsset((__int64)mode);
	DDL_GetRootState((__int64)state2, ddl_file2);
	char buffer2[200];
	memset(buffer2, 0, 200);
	sprintf_s(buffer2, xorstr_("squadMembers.loadouts.%i.weaponSetups.1.weapon"), Class);
	ParseShit(buffer2, (const char**)navStrings2, 16, &navStringCount2);
	if (DDL_MoveToPath((__int64*)&state2, (__int64*)&state2, navStringCount2, (const char**)navStrings2))
	{
		DDL_SetInt2((__int64*)&state2, (__int64*)&context2, wep);
	}
}

void setWeapon(int loadout, int weapon, int weaponId)
{
	char context[255];
	char state[255];
	int string_count;
	char* str[16]{};
	const char* mode = "";
	char buffer[200];

	if (gameMode1 == 0)
	{
		mode = xorstr_("ddl/mp/rankedloadouts.ddl");
		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 3);
	}
	else if (gameMode1 == 1)
	{
		mode = xorstr_("ddl/mp/wzrankedloadouts.ddl");
		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 5);
	}
	__int64 ddl_file = Com_DDL_LoadAsset((__int64)mode);
	DDL_GetRootState((__int64)state, ddl_file);
	memset(buffer, 0, 200);
	sprintf_s(buffer, xorstr_("squadMembers.loadouts.%i.weaponSetups.%i.weapon"), loadout, weapon);
	ParseShit(buffer, (const char**)str, 255, &string_count);
	if (DDL_MoveToPath((__int64*)&state, (__int64*)&state, string_count, (const char**)str))
	{
		DDL_SetInt((__int64)state, (__int64)context, weaponId);
	}
}

ImFont* MainCaps;
ImFont* Main;
ImFont* FMenu;
char customtag[6] = "";
char customname[255] = "";

char score[256] = "";
char games[256] = "";
char timeplayed[256] = "";
char wins[256] = "";
char top5[256] = "";
char kills[256] = "";
char deaths[256] = "";
char downs[256] = "";
int i_score = 1; //1 ~ 5555555555
int i_timeplayed = 1;
int i_games = 1; //1 ~ 5555555555
int i_wins = 1; //1 ~ 5555555555
int i_kills = 1; //1 ~ 5555555555
int i_deaths = 1; //1 ~ 5555555555
int i_downs = 1; //1 ~ 5555555555;
int i_top5 = 1; //1 ~ 5555555555
int i_top10 = 1; //1 ~ 5555555555
int i_top25 = 1; //1 ~ 5555555555

const char* weaponLoadout[117] = {
"none",
"iw8_ar_mike4",
"iw8_ar_akilo47",
"iw8_ar_asierra12",
"iw8_ar_falpha",
"iw8_ar_mcharlie",
"iw8_ar_golf36",
"iw8_ar_kilo433",
"iw8_ar_falima",
"iw8_ar_scharlie",
"iw8_sm_mpapa5",
"iw8_sm_beta",
"iw8_sm_augolf",
"iw8_sm_papa90",
"iw8_sm_mpapa7",
"iw8_sm_uzulu",
"iw8_sm_victor",
"iw8_sh_dpapa12",
"iw8_sh_charlie725",
"iw8_sh_oscar12",
"iw8_sh_romeo870",
"iw8_lm_kilo121",
"iw8_lm_pkilo",
"iw8_lm_lima86",
"iw8_lm_mgolf34",
"iw8_sn_mike14",
"iw8_sn_kilo98",
"iw8_sn_sbeta",
"iw8_sn_alpha50",
"iw8_sn_awhiskey",
"iw8_sn_delta",
"iw8_sn_hdromeo",
"iw8_sn_crossbow",
"iw8_pi_papa320",
"iw8_pi_cpapa",
"iw8_pi_mike1911",
"iw8_pi_golf21",
"iw8_pi_decho",
"iw8_la_rpapa7",
"iw8_la_gromeo",
"iw8_la_mike32",
"iw8_la_juliet",
"iw8_la_kgolf",
"iw8_knife",
"iw8_me_riotshield",
"iw8_fists",
"iw8_sm_charlie9",
"iw8_ar_tango21",
"iw8_lm_mgolf36",
"iw8_ar_sierra552",
"iw8_lm_mkilo3",
"iw8_sn_golf28",
"iw8_sm_smgolf45",
"iw8_sh_mike26",
"iw8_sn_sksierra",
"iw8_pi_mike9",
"iw8_ar_galima",
"iw8_me_hatchet",
"iw8_me_sword",
"iw8_me_kalistick",
"iw8_me_cinderblock",
"iw8_me_akimboblades",
"iw8_me_akimboblunt",
"iw8_ar_anovember94",
"iw8_sn_xmike109",
"iw8_sn_romeo700",
"iw8_lm_sierrax",
"iw8_ar_valpha",
"iw8_sh_aalpha12",
"iw8_pi_mike",
"iw8_sm_secho",
"iw8_lm_slima",
"iw8_lm_t9slowfire",
"iw8_lm_t9accurate",
"iw8_lm_t9rpapa",
"iw8_lm_t9light",
"iw8_ar_t9accurate",
"iw8_ar_t9fastburst",
"iw8_ar_t9fastfire",
"iw8_ar_t9fasthandling",
"iw8_ar_t9longburst",
"iw8_ar_t9mobility",
"iw8_ar_t9standard",
"iw8_ar_t9slowhandling",
"iw8_ar_t9damage",
"iw8_pi_t9revolver",
"iw8_pi_t9semiauto",
"iw8_pi_t9burst",
"iw8_sh_t9fullauto",
"iw8_sh_t9semiauto",
"iw8_sh_t9pump",
"iw8_sm_t9powerburst",
"iw8_sm_t9capacity",
"iw8_sm_t9burst",
"iw8_sm_t9fastfire",
"iw8_sm_t9heavy",
"iw8_sm_t9handling",
"iw8_sm_t9standard",
"iw8_sm_t9accurate",
"iw8_sm_t9spray",
"iw8_sn_t9precisionsemi",
"iw8_sn_t9damagesemi",
"iw8_sn_t9powersemi",
"iw8_sn_t9standard",
"iw8_sn_t9quickscope",
"iw8_sn_t9cannon",
"iw8_sn_t9crossbow",
"iw8_la_t9launcher",
"iw8_la_t9freefire",
"iw8_la_t9standard",
"iw8_t9knife",
"iw8_me_t9ballisticknife",
"iw8_me_t9etool",
"iw8_me_t9machete",
"iw8_me_t9sledgehammer",
"iw8_me_t9wakizashi",
"iw8_me_t9loadout"
};

void MainTab()
{
	ImGui::Dummy(ImVec2(0.0f, 1.0f));
	ImGui::Checkbox(xorstr_("FOV "), &g_vars->msettings.b_fov);
	if (g_vars->msettings.b_fov) {
		dvar_set2("NSSLSNKPN", g_vars->msettings.f_fov);
	}
	ImGui::SameLine();
	ImGui::SliderFloat(xorstr_("##FOVSLIDER"), &g_vars->msettings.f_fov, 1.0f, 2.0f, "%.1f");
	ImGui::Dummy(ImVec2(0.0f, 1.0f));
	ImGui::Checkbox(xorstr_("MAP "), &g_vars->msettings.b_map);
	if (g_vars->msettings.b_map) {
		dvar_set2("MKMRRLNRTM", g_vars->msettings.f_map);
	}
	ImGui::SameLine();
	ImGui::SliderFloat(xorstr_("##MAPSLIDER"), &g_vars->msettings.f_map, 1.0f, 2.0f, "%.1f");
	ImGui::Checkbox(xorstr_("Disable Loot Checks"), &g_vars->msettings.b_ownership);
	if (g_vars->msettings.b_ownership)
	{
		dvar_set2("NRQQOMLOQL", 0);
		dvar_set2("RRTLRKKTT", 0);
		dvar_set2("MKQPRPLQKL", 0);
	}
	else
	{
		dvar_set2("NRQQOMLOQL", 1);
		dvar_set2("RRTLRKKTT", 1);
		dvar_set2("MKQPRPLQKL", 1);
	}
	ImGui::SameLine();
	ImGui::Checkbox(xorstr_("Dynamic Third Person"), &g_vars->msettings.b_dynamic3p);
	ImGui::Checkbox(xorstr_("No Fog "), &g_vars->msettings.b_fog);
	if (g_vars->msettings.b_fog)
	{
		dvar_set2("LTOKRMRTMM", 0);
	}
	else
	{
		dvar_set2("LTOKRMRTMM", 1);
	}
	ImGui::SameLine();
	ImGui::Checkbox(xorstr_("Max Bright "), &g_vars->msettings.b_brightmax);
	if (g_vars->msettings.b_brightmax) {
		dvar_set2("NQKKOONQPR", 0);
		dvar_set2("MTLMSQMNTR", 0);
		dvar_set2("RNPPKQOTN", 0);
		dvar_set2("LKOLRONRNQ", 0);
		dvar_set2("LTOKRMRTMM", 0);
	}
	else
	{
		dvar_set2("NQKKOONQPR", 1);
		dvar_set2("MTLMSQMNTR", 1);
		dvar_set2("RNPPKQOTN", 1);
		dvar_set2("LKOLRONRNQ", 1);
		dvar_set2("LTOKRMRTMM", 1);
	}
	ImGui::SameLine();
	ImGui::Checkbox(xorstr_("Heartbeat Cheat "), &g_vars->msettings.b_heartcheat);
	if (g_vars->msettings.b_heartcheat)
	{
		dvar_set2("NSKNMSMOLP", 2);
		dvar_set2("NLLRSSOQMQ", 10000);
	}
	else
	{
		dvar_set2("NSKNMSMOLP", 5);
		dvar_set2("NLLRSSOQMQ", 500);
	}
	ImGui::Checkbox(xorstr_("No Gun "), &g_vars->msettings.b_nogun);
	if (g_vars->msettings.b_nogun)
	{
		dvar_set2("SROLTPQLK", 0);
	}
	else
	{
		dvar_set2("SROLTPQLK", 1);
	}
	ImGui::SameLine();
	ImGui::Checkbox(xorstr_("Third Person "), &g_vars->msettings.b_thirdperson);
	if (g_vars->msettings.b_thirdperson)
	{
		dvar_set2("NOSLRNTRKL", 1);
	}
	else
	{
		dvar_set2("NOSLRNTRKL", 0);
	}

	ImGui::SameLine();
	ImGui::Checkbox(xorstr_("Mess up View "), &g_vars->msettings.b_view);
	if (g_vars->msettings.b_view)
	{
		dvar_set2("LLLRKRROOP", 1);
	}
	else
	{
		dvar_set2("LLLRKRROOP", 0);
	}
	
	ImGui::Separator();
	ImGui::TextDisabled("Misc Stuff");
	if (ImGui::Button(xorstr_("Profanity Names"), ImVec2(200, 31)))
	{
		dvar_set2("PLTMTSLKT", 0);
	}
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Skip Tutorial"), ImVec2(200, 31)))
	{
		dvar_set2(xorstr_("LSPSKLPNQT"), 1);
	}
	if (ImGui::Button(xorstr_("Private Match"), ImVec2(200, 31)))
	{
		dvar_set2(xorstr_("LOQQOSNQKN"), 1);
		dvar_set2(xorstr_("PKMLMMTSN"), 1);
	}
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("FPS Boost"), ImVec2(200, 31)))
	{
		dvar_set2("OPOTTRRNQ", 0);
		dvar_set2("NNRQTQNLRL", 0);
		dvar_set2("NNTOQLMSLO", 3);
		dvar_set2("NTROOKOSPM", 3);
		dvar_set2("NNKRMTSNPL", 0);
		dvar_set2("MOLLKMTMRS", 0);
		dvar_set2("MQOPRPQLQL", 0);
		dvar_set2("NLNKQNROQM", 0);
		dvar_set2("LTOKRMRTMM", 0);
	}
	if (ImGui::Button(xorstr_("Unlock All"), ImVec2(-1, 31)))
	{
		unlock();
	}
}

void EhmTab()
{
	ImGui::TextDisabled("Configuration");
	ImGui::RadioButton(xorstr_("MP"), &gameMode, 0);
	ImGui::SameLine();
	ImGui::RadioButton(xorstr_("WZ"), &gameMode, 1);
	ImGui::SameLine();
	ImGui::RadioButton(xorstr_("Apply One"), &applyMode, 0);
	ImGui::SameLine();
	ImGui::RadioButton(xorstr_("Apply All"), &applyMode, 1);
	ImGui::Separator();
	ImGui::TextDisabled("Camo Editor ");
	static const char* items[] = { "(MW) Gold", "(MW) Platinum", "(MW) Damascus", "(MW) Obsidian", "(CW) Gold", "(CW) Diamond", "(CW) DMU", "(CW) Golden Viper", "(CW) Plague Diamond", "(CW) Dark Aether", "(VG) Gold", "(VG) Diamond", "(VG) Atomic", "(VG) Fake Diamond", "(VG) Golden Viper", "(VG) Plague Diamond", "(VG) Dark Aether", "(CW) Cherry Blossom",  "(MW) Acticamo", "(MW) Banded", "(VG) False Prospector", "(VG) Death Prospector", "(VG) Titanium Chrome", "(VG) Liquid Metal", "(VG) Skynet" };
	static const char* current_item = "Select Camo";
	static int item_current_2 = 0;
	static int class1 = 0;
	static int class2 = 1;
	static int class3 = 2;
	static int class4 = 3;
	static int class5 = 4;
	static int class6 = 5;
	static int class7 = 6;
	static int class8 = 7;
	static int class9 = 8;
	static int class10 = 9;
	static int primary = 0;
	static int secondary = 1;
	ImGui::Combo("                   ", &item_current_2, xorstr_("Class 1\0Class 2\0Class 3\0Class 4\0Class 5\0Class 6\0Class 7\0Class 8\0Class 9\0Class 10\0\0"));
	static int item_current_3 = 0;
	ImGui::Combo("           ", &item_current_3, xorstr_("Primary\0Secondary\0\0"));
	if (ImGui::BeginCombo(xorstr_("##combo"), current_item))
	{
		for (int n = 0; n < IM_ARRAYSIZE(items); n++)
		{
			bool is_selected = (current_item == items[n]);
			if (ImGui::Selectable(items[n], is_selected))
				current_item = items[n];
			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Camo"), ImVec2(-1, 30)))
	{
		if (applyMode == 0)
		{
			if (current_item == "(MW) Gold")
				SetCamo(item_current_2, item_current_3, 111);

			if (current_item == "(MW) Platinum")
				SetCamo(item_current_2, item_current_3, 112);

			if (current_item == "(MW) Damascus")
				SetCamo(item_current_2, item_current_3, 113);

			if (current_item == "(MW) Obsidian")
				SetCamo(item_current_2, item_current_3, 114);

			if (current_item == "(CW) Gold")
				SetCamo(item_current_2, item_current_3, 133);

			if (current_item == "(CW) Diamond")
				SetCamo(item_current_2, item_current_3, 134);

			if (current_item == "(CW) DMU")
				SetCamo(item_current_2, item_current_3, 135);

			if (current_item == "(CW) Golden Viper")
				SetCamo(item_current_2, item_current_3, 242);

			if (current_item == "(CW) Plague Diamond")
				SetCamo(item_current_2, item_current_3, 243);

			if (current_item == "(CW) Dark Aether")
				SetCamo(item_current_2, item_current_3, 244);

			if (current_item == "(VG) Gold")
				SetCamo(item_current_2, item_current_3, 345);

			if (current_item == "(VG) Diamond")
				SetCamo(item_current_2, item_current_3, 346);

			if (current_item == "(VG) Atomic")
				SetCamo(item_current_2, item_current_3, 350);

			if (current_item == "(VG) Fake Diamond")
				SetCamo(item_current_2, item_current_3, 349);

			if (current_item == "(VG) Golden Viper")
				SetCamo(item_current_2, item_current_3, 402);

			if (current_item == "(VG) Plague Diamond")
				SetCamo(item_current_2, item_current_3, 403);

			if (current_item == "(VG) Dark Aether")
				SetCamo(item_current_2, item_current_3, 404);

			if (current_item == "(CW) Cherry Blossom")
				SetCamo(item_current_2, item_current_3, 160);

			if (current_item == "(MW) Acticamo")
				SetCamo(item_current_2, item_current_3, 2);

			if (current_item == "(MW) Banded")
				SetCamo(item_current_2, item_current_3, 3);

			if (current_item == "(VG) False Prospector")
				SetCamo(item_current_2, item_current_3, 509);

			if (current_item == "(VG) Death Prospector")
				SetCamo(item_current_2, item_current_3, 510);

			if (current_item == "(VG) Titanium Chrome")
				SetCamo(item_current_2, item_current_3, 511);

			if (current_item == "(VG) Liquid Metal")
				SetCamo(item_current_2, item_current_3, 512);

			if (current_item == "(VG) Skynet")
				SetCamo(item_current_2, item_current_3, 513);
		}

		if (applyMode == 1)
		{
			if (current_item == "(MW) Gold")
				SetCamo(class1, primary, 111),
				SetCamo(class2, primary, 111),
				SetCamo(class3, primary, 111),
				SetCamo(class4, primary, 111),
				SetCamo(class5, primary, 111),
				SetCamo(class6, primary, 111),
				SetCamo(class7, primary, 111),
				SetCamo(class8, primary, 111),
				SetCamo(class9, primary, 111),
				SetCamo(class10, primary, 111),
				SetCamo(class1, secondary, 111),
				SetCamo(class2, secondary, 111),
				SetCamo(class3, secondary, 111),
				SetCamo(class4, secondary, 111),
				SetCamo(class5, secondary, 111),
				SetCamo(class6, secondary, 111),
				SetCamo(class7, secondary, 111),
				SetCamo(class8, secondary, 111),
				SetCamo(class9, secondary, 111),
				SetCamo(class10, secondary, 111);

			if (current_item == "(MW) Platinum")
				SetCamo(class1, primary, 112),
				SetCamo(class2, primary, 112),
				SetCamo(class3, primary, 112),
				SetCamo(class4, primary, 112),
				SetCamo(class5, primary, 112),
				SetCamo(class6, primary, 112),
				SetCamo(class7, primary, 112),
				SetCamo(class8, primary, 112),
				SetCamo(class9, primary, 112),
				SetCamo(class10, primary, 112),
				SetCamo(class1, secondary, 112),
				SetCamo(class2, secondary, 112),
				SetCamo(class3, secondary, 112),
				SetCamo(class4, secondary, 112),
				SetCamo(class5, secondary, 112),
				SetCamo(class6, secondary, 112),
				SetCamo(class7, secondary, 112),
				SetCamo(class8, secondary, 112),
				SetCamo(class9, secondary, 112),
				SetCamo(class10, secondary, 112);

			if (current_item == "(MW) Damascus")
				SetCamo(class1, primary, 113),
				SetCamo(class2, primary, 113),
				SetCamo(class3, primary, 113),
				SetCamo(class4, primary, 113),
				SetCamo(class5, primary, 113),
				SetCamo(class6, primary, 113),
				SetCamo(class7, primary, 113),
				SetCamo(class8, primary, 113),
				SetCamo(class9, primary, 113),
				SetCamo(class10, primary, 113),
				SetCamo(class1, secondary, 113),
				SetCamo(class2, secondary, 113),
				SetCamo(class3, secondary, 113),
				SetCamo(class4, secondary, 113),
				SetCamo(class5, secondary, 113),
				SetCamo(class6, secondary, 113),
				SetCamo(class7, secondary, 113),
				SetCamo(class8, secondary, 113),
				SetCamo(class9, secondary, 113),
				SetCamo(class10, secondary, 113);

			if (current_item == "(MW) Obsidian")
				SetCamo(class1, primary, 114),
				SetCamo(class2, primary, 114),
				SetCamo(class3, primary, 114),
				SetCamo(class4, primary, 114),
				SetCamo(class5, primary, 114),
				SetCamo(class6, primary, 114),
				SetCamo(class7, primary, 114),
				SetCamo(class8, primary, 114),
				SetCamo(class9, primary, 114),
				SetCamo(class10, primary, 114),
				SetCamo(class1, secondary, 114),
				SetCamo(class2, secondary, 114),
				SetCamo(class3, secondary, 114),
				SetCamo(class4, secondary, 114),
				SetCamo(class5, secondary, 114),
				SetCamo(class6, secondary, 114),
				SetCamo(class7, secondary, 114),
				SetCamo(class8, secondary, 114),
				SetCamo(class9, secondary, 114),
				SetCamo(class10, secondary, 114);

			if (current_item == "(CW) Gold")
				SetCamo(class1, primary, 133),
				SetCamo(class2, primary, 133),
				SetCamo(class3, primary, 133),
				SetCamo(class4, primary, 133),
				SetCamo(class5, primary, 133),
				SetCamo(class6, primary, 133),
				SetCamo(class7, primary, 133),
				SetCamo(class8, primary, 133),
				SetCamo(class9, primary, 133),
				SetCamo(class10, primary, 133),
				SetCamo(class1, secondary, 133),
				SetCamo(class2, secondary, 133),
				SetCamo(class3, secondary, 133),
				SetCamo(class4, secondary, 133),
				SetCamo(class5, secondary, 133),
				SetCamo(class6, secondary, 133),
				SetCamo(class7, secondary, 133),
				SetCamo(class8, secondary, 133),
				SetCamo(class9, secondary, 133),
				SetCamo(class10, secondary, 133);

			if (current_item == "(CW) Diamond")
				SetCamo(class1, primary, 134),
				SetCamo(class2, primary, 134),
				SetCamo(class3, primary, 134),
				SetCamo(class4, primary, 134),
				SetCamo(class5, primary, 134),
				SetCamo(class6, primary, 134),
				SetCamo(class7, primary, 134),
				SetCamo(class8, primary, 134),
				SetCamo(class9, primary, 134),
				SetCamo(class10, primary, 134),
				SetCamo(class1, secondary, 134),
				SetCamo(class2, secondary, 134),
				SetCamo(class3, secondary, 134),
				SetCamo(class4, secondary, 134),
				SetCamo(class5, secondary, 134),
				SetCamo(class6, secondary, 134),
				SetCamo(class7, secondary, 134),
				SetCamo(class8, secondary, 134),
				SetCamo(class9, secondary, 134),
				SetCamo(class10, secondary, 134);

			if (current_item == "(CW) DMU")
				SetCamo(class1, primary, 135),
				SetCamo(class2, primary, 135),
				SetCamo(class3, primary, 135),
				SetCamo(class4, primary, 135),
				SetCamo(class5, primary, 135),
				SetCamo(class6, primary, 135),
				SetCamo(class7, primary, 135),
				SetCamo(class8, primary, 135),
				SetCamo(class9, primary, 135),
				SetCamo(class10, primary, 135),
				SetCamo(class1, secondary, 135),
				SetCamo(class2, secondary, 135),
				SetCamo(class3, secondary, 135),
				SetCamo(class4, secondary, 135),
				SetCamo(class5, secondary, 135),
				SetCamo(class6, secondary, 135),
				SetCamo(class7, secondary, 135),
				SetCamo(class8, secondary, 135),
				SetCamo(class9, secondary, 135),
				SetCamo(class10, secondary, 135);

			if (current_item == "(CW) Golden Viper")
				SetCamo(class1, primary, 242),
				SetCamo(class2, primary, 242),
				SetCamo(class3, primary, 242),
				SetCamo(class4, primary, 242),
				SetCamo(class5, primary, 242),
				SetCamo(class6, primary, 242),
				SetCamo(class7, primary, 242),
				SetCamo(class8, primary, 242),
				SetCamo(class9, primary, 242),
				SetCamo(class10, primary, 242),
				SetCamo(class1, secondary, 242),
				SetCamo(class2, secondary, 242),
				SetCamo(class3, secondary, 242),
				SetCamo(class4, secondary, 242),
				SetCamo(class5, secondary, 242),
				SetCamo(class6, secondary, 242),
				SetCamo(class7, secondary, 242),
				SetCamo(class8, secondary, 242),
				SetCamo(class9, secondary, 242),
				SetCamo(class10, secondary, 242);

			if (current_item == "(CW) Plague Diamond")
				SetCamo(class1, primary, 243),
				SetCamo(class2, primary, 243),
				SetCamo(class3, primary, 243),
				SetCamo(class4, primary, 243),
				SetCamo(class5, primary, 243),
				SetCamo(class6, primary, 243),
				SetCamo(class7, primary, 243),
				SetCamo(class8, primary, 243),
				SetCamo(class9, primary, 243),
				SetCamo(class10, primary, 243),
				SetCamo(class1, secondary, 243),
				SetCamo(class2, secondary, 243),
				SetCamo(class3, secondary, 243),
				SetCamo(class4, secondary, 243),
				SetCamo(class5, secondary, 243),
				SetCamo(class6, secondary, 243),
				SetCamo(class7, secondary, 243),
				SetCamo(class8, secondary, 243),
				SetCamo(class9, secondary, 243),
				SetCamo(class10, secondary, 243);

			if (current_item == "(CW) Dark Aether")
				SetCamo(class1, primary, 244),
				SetCamo(class2, primary, 244),
				SetCamo(class3, primary, 244),
				SetCamo(class4, primary, 244),
				SetCamo(class5, primary, 244),
				SetCamo(class6, primary, 244),
				SetCamo(class7, primary, 244),
				SetCamo(class8, primary, 244),
				SetCamo(class9, primary, 244),
				SetCamo(class10, primary, 244),
				SetCamo(class1, secondary, 244),
				SetCamo(class2, secondary, 244),
				SetCamo(class3, secondary, 244),
				SetCamo(class4, secondary, 244),
				SetCamo(class5, secondary, 244),
				SetCamo(class6, secondary, 244),
				SetCamo(class7, secondary, 244),
				SetCamo(class8, secondary, 244),
				SetCamo(class9, secondary, 244),
				SetCamo(class10, secondary, 244);

			if (current_item == "(VG) Gold")
				SetCamo(class1, primary, 345),
				SetCamo(class2, primary, 345),
				SetCamo(class3, primary, 345),
				SetCamo(class4, primary, 345),
				SetCamo(class5, primary, 345),
				SetCamo(class6, primary, 345),
				SetCamo(class7, primary, 345),
				SetCamo(class8, primary, 345),
				SetCamo(class9, primary, 345),
				SetCamo(class10, primary, 345),
				SetCamo(class1, secondary, 345),
				SetCamo(class2, secondary, 345),
				SetCamo(class3, secondary, 345),
				SetCamo(class4, secondary, 345),
				SetCamo(class5, secondary, 345),
				SetCamo(class6, secondary, 345),
				SetCamo(class7, secondary, 345),
				SetCamo(class8, secondary, 345),
				SetCamo(class9, secondary, 345),
				SetCamo(class10, secondary, 345);

			if (current_item == "(VG) Diamond")
				SetCamo(class1, primary, 346),
				SetCamo(class2, primary, 346),
				SetCamo(class3, primary, 346),
				SetCamo(class4, primary, 346),
				SetCamo(class5, primary, 346),
				SetCamo(class6, primary, 346),
				SetCamo(class7, primary, 346),
				SetCamo(class8, primary, 346),
				SetCamo(class9, primary, 346),
				SetCamo(class10, primary, 346),
				SetCamo(class1, secondary, 346),
				SetCamo(class2, secondary, 346),
				SetCamo(class3, secondary, 346),
				SetCamo(class4, secondary, 346),
				SetCamo(class5, secondary, 346),
				SetCamo(class6, secondary, 346),
				SetCamo(class7, secondary, 346),
				SetCamo(class8, secondary, 346),
				SetCamo(class9, secondary, 346),
				SetCamo(class10, secondary, 346);

			if (current_item == "(VG) Atomic")
				SetCamo(class1, primary, 350),
				SetCamo(class2, primary, 350),
				SetCamo(class3, primary, 350),
				SetCamo(class4, primary, 350),
				SetCamo(class5, primary, 350),
				SetCamo(class6, primary, 350),
				SetCamo(class7, primary, 350),
				SetCamo(class8, primary, 350),
				SetCamo(class9, primary, 350),
				SetCamo(class10, primary, 350),
				SetCamo(class1, secondary, 350),
				SetCamo(class2, secondary, 350),
				SetCamo(class3, secondary, 350),
				SetCamo(class4, secondary, 350),
				SetCamo(class5, secondary, 350),
				SetCamo(class6, secondary, 350),
				SetCamo(class7, secondary, 350),
				SetCamo(class8, secondary, 350),
				SetCamo(class9, secondary, 350),
				SetCamo(class10, secondary, 350);

			if (current_item == "(VG) Fake Diamond")
				SetCamo(class1, primary, 349),
				SetCamo(class2, primary, 349),
				SetCamo(class3, primary, 349),
				SetCamo(class4, primary, 349),
				SetCamo(class5, primary, 349),
				SetCamo(class6, primary, 349),
				SetCamo(class7, primary, 349),
				SetCamo(class8, primary, 349),
				SetCamo(class9, primary, 349),
				SetCamo(class10, primary, 349),
				SetCamo(class1, secondary, 349),
				SetCamo(class2, secondary, 349),
				SetCamo(class3, secondary, 349),
				SetCamo(class4, secondary, 349),
				SetCamo(class5, secondary, 349),
				SetCamo(class6, secondary, 349),
				SetCamo(class7, secondary, 349),
				SetCamo(class8, secondary, 349),
				SetCamo(class9, secondary, 349),
				SetCamo(class10, secondary, 349);

			if (current_item == "(VG) Golden Viper")
				SetCamo(class1, primary, 402),
				SetCamo(class2, primary, 402),
				SetCamo(class3, primary, 402),
				SetCamo(class4, primary, 402),
				SetCamo(class5, primary, 402),
				SetCamo(class6, primary, 402),
				SetCamo(class7, primary, 402),
				SetCamo(class8, primary, 402),
				SetCamo(class9, primary, 402),
				SetCamo(class10, primary, 402),
				SetCamo(class1, secondary, 402),
				SetCamo(class2, secondary, 402),
				SetCamo(class3, secondary, 402),
				SetCamo(class4, secondary, 402),
				SetCamo(class5, secondary, 402),
				SetCamo(class6, secondary, 402),
				SetCamo(class7, secondary, 402),
				SetCamo(class8, secondary, 402),
				SetCamo(class9, secondary, 402),
				SetCamo(class10, secondary, 402);

			if (current_item == "(VG) Plague Diamond")
				SetCamo(class1, primary, 403),
				SetCamo(class2, primary, 403),
				SetCamo(class3, primary, 403),
				SetCamo(class4, primary, 403),
				SetCamo(class5, primary, 403),
				SetCamo(class6, primary, 403),
				SetCamo(class7, primary, 403),
				SetCamo(class8, primary, 403),
				SetCamo(class9, primary, 403),
				SetCamo(class10, primary, 403),
				SetCamo(class1, secondary, 403),
				SetCamo(class2, secondary, 403),
				SetCamo(class3, secondary, 403),
				SetCamo(class4, secondary, 403),
				SetCamo(class5, secondary, 403),
				SetCamo(class6, secondary, 403),
				SetCamo(class7, secondary, 403),
				SetCamo(class8, secondary, 403),
				SetCamo(class9, secondary, 403),
				SetCamo(class10, secondary, 403);

			if (current_item == "(VG) Dark Aether")
				SetCamo(class1, primary, 404),
				SetCamo(class2, primary, 404),
				SetCamo(class3, primary, 404),
				SetCamo(class4, primary, 404),
				SetCamo(class5, primary, 404),
				SetCamo(class6, primary, 404),
				SetCamo(class7, primary, 404),
				SetCamo(class8, primary, 404),
				SetCamo(class9, primary, 404),
				SetCamo(class10, primary, 404),
				SetCamo(class1, secondary, 404),
				SetCamo(class2, secondary, 404),
				SetCamo(class3, secondary, 404),
				SetCamo(class4, secondary, 404),
				SetCamo(class5, secondary, 404),
				SetCamo(class6, secondary, 404),
				SetCamo(class7, secondary, 404),
				SetCamo(class8, secondary, 404),
				SetCamo(class9, secondary, 404),
				SetCamo(class10, secondary, 404);

			if (current_item == "(CW) Cherry Blossom")
				SetCamo(class1, primary, 160),
				SetCamo(class2, primary, 160),
				SetCamo(class3, primary, 160),
				SetCamo(class4, primary, 160),
				SetCamo(class5, primary, 160),
				SetCamo(class6, primary, 160),
				SetCamo(class7, primary, 160),
				SetCamo(class8, primary, 160),
				SetCamo(class9, primary, 160),
				SetCamo(class10, primary, 160),
				SetCamo(class1, secondary, 160),
				SetCamo(class2, secondary, 160),
				SetCamo(class3, secondary, 160),
				SetCamo(class4, secondary, 160),
				SetCamo(class5, secondary, 160),
				SetCamo(class6, secondary, 160),
				SetCamo(class7, secondary, 160),
				SetCamo(class8, secondary, 160),
				SetCamo(class9, secondary, 160),
				SetCamo(class10, secondary, 160);

			if (current_item == "(MW) Acticamo")
				SetCamo(class1, primary, 2),
				SetCamo(class2, primary, 2),
				SetCamo(class3, primary, 2),
				SetCamo(class4, primary, 2),
				SetCamo(class5, primary, 2),
				SetCamo(class6, primary, 2),
				SetCamo(class7, primary, 2),
				SetCamo(class8, primary, 2),
				SetCamo(class9, primary, 2),
				SetCamo(class10, primary, 2),
				SetCamo(class1, secondary, 2),
				SetCamo(class2, secondary, 2),
				SetCamo(class3, secondary, 2),
				SetCamo(class4, secondary, 2),
				SetCamo(class5, secondary, 2),
				SetCamo(class6, secondary, 2),
				SetCamo(class7, secondary, 2),
				SetCamo(class8, secondary, 2),
				SetCamo(class9, secondary, 2),
				SetCamo(class10, secondary, 2);

			if (current_item == "(MW) Banded")
				SetCamo(class1, primary, 3),
				SetCamo(class2, primary, 3),
				SetCamo(class3, primary, 3),
				SetCamo(class4, primary, 3),
				SetCamo(class5, primary, 3),
				SetCamo(class6, primary, 3),
				SetCamo(class7, primary, 3),
				SetCamo(class8, primary, 3),
				SetCamo(class9, primary, 3),
				SetCamo(class10, primary, 3),
				SetCamo(class1, secondary, 3),
				SetCamo(class2, secondary, 3),
				SetCamo(class3, secondary, 3),
				SetCamo(class4, secondary, 3),
				SetCamo(class5, secondary, 3),
				SetCamo(class6, secondary, 3),
				SetCamo(class7, secondary, 3),
				SetCamo(class8, secondary, 3),
				SetCamo(class9, secondary, 3),
				SetCamo(class10, secondary, 3);

			if (current_item == "(VG) False Prospector")
				SetCamo(class1, primary, 509),
				SetCamo(class2, primary, 509),
				SetCamo(class3, primary, 509),
				SetCamo(class4, primary, 509),
				SetCamo(class5, primary, 509),
				SetCamo(class6, primary, 509),
				SetCamo(class7, primary, 509),
				SetCamo(class8, primary, 509),
				SetCamo(class9, primary, 509),
				SetCamo(class10, primary, 509),
				SetCamo(class1, secondary, 509),
				SetCamo(class2, secondary, 509),
				SetCamo(class3, secondary, 509),
				SetCamo(class4, secondary, 509),
				SetCamo(class5, secondary, 509),
				SetCamo(class6, secondary, 509),
				SetCamo(class7, secondary, 509),
				SetCamo(class8, secondary, 509),
				SetCamo(class9, secondary, 509),
				SetCamo(class10, secondary, 509);

			if (current_item == "(VG) Death Prospector")
				SetCamo(class1, primary, 510),
				SetCamo(class2, primary, 510),
				SetCamo(class3, primary, 510),
				SetCamo(class4, primary, 510),
				SetCamo(class5, primary, 510),
				SetCamo(class6, primary, 510),
				SetCamo(class7, primary, 510),
				SetCamo(class8, primary, 510),
				SetCamo(class9, primary, 510),
				SetCamo(class10, primary, 510),
				SetCamo(class1, secondary, 510),
				SetCamo(class2, secondary, 510),
				SetCamo(class3, secondary, 510),
				SetCamo(class4, secondary, 510),
				SetCamo(class5, secondary, 510),
				SetCamo(class6, secondary, 510),
				SetCamo(class7, secondary, 510),
				SetCamo(class8, secondary, 510),
				SetCamo(class9, secondary, 510),
				SetCamo(class10, secondary, 510);

			if (current_item == "(VG) Titanium Chrome")
				SetCamo(class1, primary, 511),
				SetCamo(class2, primary, 511),
				SetCamo(class3, primary, 511),
				SetCamo(class4, primary, 511),
				SetCamo(class5, primary, 511),
				SetCamo(class6, primary, 511),
				SetCamo(class7, primary, 511),
				SetCamo(class8, primary, 511),
				SetCamo(class9, primary, 511),
				SetCamo(class10, primary, 511),
				SetCamo(class1, secondary, 511),
				SetCamo(class2, secondary, 511),
				SetCamo(class3, secondary, 511),
				SetCamo(class4, secondary, 511),
				SetCamo(class5, secondary, 511),
				SetCamo(class6, secondary, 511),
				SetCamo(class7, secondary, 511),
				SetCamo(class8, secondary, 511),
				SetCamo(class9, secondary, 511),
				SetCamo(class10, secondary, 511);

			if (current_item == "(VG) Liquid Metal")
				SetCamo(class1, primary, 512),
				SetCamo(class2, primary, 512),
				SetCamo(class3, primary, 512),
				SetCamo(class4, primary, 512),
				SetCamo(class5, primary, 512),
				SetCamo(class6, primary, 512),
				SetCamo(class7, primary, 512),
				SetCamo(class8, primary, 512),
				SetCamo(class9, primary, 512),
				SetCamo(class10, primary, 512),
				SetCamo(class1, secondary, 512),
				SetCamo(class2, secondary, 512),
				SetCamo(class3, secondary, 512),
				SetCamo(class4, secondary, 512),
				SetCamo(class5, secondary, 512),
				SetCamo(class6, secondary, 512),
				SetCamo(class7, secondary, 512),
				SetCamo(class8, secondary, 512),
				SetCamo(class9, secondary, 512),
				SetCamo(class10, secondary, 512);

			if (current_item == "(VG) Skynet")
				SetCamo(class1, primary, 513),
				SetCamo(class2, primary, 513),
				SetCamo(class3, primary, 513),
				SetCamo(class4, primary, 513),
				SetCamo(class5, primary, 513),
				SetCamo(class6, primary, 513),
				SetCamo(class7, primary, 513),
				SetCamo(class8, primary, 513),
				SetCamo(class9, primary, 513),
				SetCamo(class10, primary, 513),
				SetCamo(class1, secondary, 513),
				SetCamo(class2, secondary, 513),
				SetCamo(class3, secondary, 513),
				SetCamo(class4, secondary, 513),
				SetCamo(class5, secondary, 513),
				SetCamo(class6, secondary, 513),
				SetCamo(class7, secondary, 513),
				SetCamo(class8, secondary, 513),
				SetCamo(class9, secondary, 513),
				SetCamo(class10, secondary, 513);
		}
	}
	ImGui::Separator();
	ImGui::TextDisabled("Developer Tags ");
	static const char* itemclantag[] = { "Logo IW", "Logo RVN", "Logo SHG","Logo DW","Logo HMS","Logo BNOX","Logo 3ARC","Logo VV","Logo TFB", "Logo KING", "Logo BLIZZARD", "Red 1W","Red LW","Red IW DEV","Red RAVN","Red RAVEN","Red R4VEN", "Red OW", "Red BN0X","Red 34RC","Red ATVI" };
	static const char* current_clantag = "Select Clan Tag";
	if (ImGui::BeginCombo("##combo4", current_clantag)) // The second parameter is the label previewed before opening the combo.
	{
		for (int n = 0; n < IM_ARRAYSIZE(itemclantag); n++)
		{
			bool is_selected4 = (current_clantag == itemclantag[n]); // You can store your selection however you want, outside or inside your objects
			if (ImGui::Selectable(itemclantag[n], is_selected4))
				current_clantag = itemclantag[n];
			if (is_selected4)
				ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
		}
		ImGui::EndCombo();
	}
	ImGui::SameLine();

	if (ImGui::Button(xorstr_("Set Tag"), ImVec2(-1, 30))) {
		if (current_clantag == "Logo IW")
			CL_PlayerData_SetCustomClanTag("iw");
		if (current_clantag == "Logo RVN")
			CL_PlayerData_SetCustomClanTag("rvn");
		if (current_clantag == "Logo SHG")
			CL_PlayerData_SetCustomClanTag("shg");
		if (current_clantag == "Logo DW")
			CL_PlayerData_SetCustomClanTag("dw");
		if (current_clantag == "Logo HMS")
			CL_PlayerData_SetCustomClanTag("hms");
		if (current_clantag == "Logo BNOX")
			CL_PlayerData_SetCustomClanTag("bnox");
		if (current_clantag == "Logo 3ARC")
			CL_PlayerData_SetCustomClanTag("3arc");
		if (current_clantag == "Logo VV")
			CL_PlayerData_SetCustomClanTag("vv");
		if (current_clantag == "Logo TFB")
			CL_PlayerData_SetCustomClanTag("tfb");
		if (current_clantag == "Logo KING")
			CL_PlayerData_SetCustomClanTag("king");
		if (current_clantag == "Logo BLIZZARD")
			CL_PlayerData_SetCustomClanTag("bliz");
		if (current_clantag == "Red 1W")
			CL_PlayerData_SetCustomClanTag("1W");
		if (current_clantag == "Red LW")
			CL_PlayerData_SetCustomClanTag("LW");
		if (current_clantag == "Red IW DEV")
			CL_PlayerData_SetCustomClanTag("IWDev");
		if (current_clantag == "Red RAVN")
			CL_PlayerData_SetCustomClanTag("RAVN");
		if (current_clantag == "Red RAVEN")
			CL_PlayerData_SetCustomClanTag("RAVEN");
		if (current_clantag == "Red R4VEN")
			CL_PlayerData_SetCustomClanTag("R4VEN");
		if (current_clantag == "Red OW")
			CL_PlayerData_SetCustomClanTag("OW");
		if (current_clantag == "Red BN0X")
			CL_PlayerData_SetCustomClanTag("BN0X");
		if (current_clantag == "Red 34RC")
			CL_PlayerData_SetCustomClanTag("34RC");
		if (current_clantag == "Red ATVI")
			CL_PlayerData_SetCustomClanTag("ATVI");
	}
	ImGui::InputTextWithHint(xorstr_("##KeyInput"), xorstr_("Enter Custom Tag"), customtag, 6);
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Custom"), ImVec2(-1, 30)))
	{
		CL_PlayerData_SetCustomClanTag(customtag);
	}
}

void VisualsTab()
{
	ImGui::TextDisabled("Configuration");
	ImGui::RadioButton(xorstr_("MP"), &gameMode1, 0);
	ImGui::SameLine();
	ImGui::RadioButton(xorstr_("WZ"), &gameMode1, 1);
	ImGui::SameLine();
	ImGui::RadioButton(xorstr_("Apply One"), &applyMode1, 0);
	ImGui::SameLine();
	ImGui::RadioButton(xorstr_("Apply All"), &applyMode1, 1);
	ImGui::RadioButton(xorstr_("Set Primary Gun"), &weapontype, 0);
	ImGui::SameLine();
	ImGui::RadioButton(xorstr_("Set Secondary Gun"), &weapontype, 1);
	static int class1 = 0;
	static int class2 = 1;
	static int class3 = 2;
	static int class4 = 3;
	static int class5 = 4;
	static int class6 = 5;
	static int class7 = 6;
	static int class8 = 7;
	static int class9 = 8;
	static int class10 = 9;
	static int gunint = 0;
	ImGui::Separator();
	ImGui::TextDisabled("Weapon Editor ");
	static int item_current_6 = 0;
	ImGui::Combo("##Classes", &item_current_6, xorstr_("Class 1\0Class 2\0Class 3\0Class 4\0Class 5\0Class 6\0Class 7\0Class 8\0Class 9\0Class 10\0\0"));
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Double Guns"), ImVec2(-1, 30)))
	{
		if (applyMode1 == 0)
		{
			CopyWeapon(item_current_6);
		}
		if (applyMode1 == 1)
		{
			CopyWeapon(item_current_6);
			CopyWeapon(class2);
			CopyWeapon(class3);
			CopyWeapon(class4);
			CopyWeapon(class5);
			CopyWeapon(class6);
			CopyWeapon(class7);
			CopyWeapon(class8);
			CopyWeapon(class9);
			CopyWeapon(class10);
		}
	}
	ImGui::Combo("##GunsID", &gunint, weaponLoadout, 117);
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Weapon"), ImVec2(-1, 30)))
	{
		setWeapon(item_current_6, weapontype, gunint);
	}
	ImGui::Separator();
	ImGui::TextDisabled("Class Name Editor");
	static int item_current_4 = 0;
	ImGui::Combo("##Class", &item_current_4, xorstr_("Class 1\0Class 2\0Class 3\0Class 4\0Class 5\0Class 6\0Class 7\0Class 8\0Class 9\0Class 10\0\0"));
	ImGui::InputTextWithHint(xorstr_("##InputClass"), xorstr_("Enter Class Name"), customname, 255);
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Class Name"), ImVec2(-1, 30)))
	{
		if (applyMode1 == 0)
		{
			SetName(item_current_4, customname);
		}

		if (applyMode1 == 1)
		{
			SetName(item_current_4, customname);
			SetName(class2, customname);
			SetName(class3, customname);
			SetName(class4, customname);
			SetName(class5, customname);
			SetName(class6, customname);
			SetName(class7, customname);
			SetName(class8, customname);
			SetName(class9, customname);
			SetName(class10, customname);
		}
	}
}

void RebirthTab()
{
	ImGui::TextDisabled(xorstr_(" Step 1. Change the number for Stats and hit Set.\n Step 2. Go into a game start and kill yourself.\n Make sure you kill yourself after the Pregamelobby!"));
	ImGui::SliderInt("##WINS", &i_wins, 1, 9999999, "Wins %d");
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Wins"), ImVec2(-1, 30)))
	{
		char context[255];
		char state[255];

		__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

		DDL_GetRootState((__int64)state, ddl_file);

		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br_rebirth");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"wins");

		DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_wins);
	}

	/*ImGui::Dummy(ImVec2(0.0f, 3.0f));*/
	ImGui::SliderInt("##TOP5", &i_top5, 1, 9999999, "Top 5 %d");
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Top5"), ImVec2(-1, 30)))
	{
		char context[255];
		char state[255];

		__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

		DDL_GetRootState((__int64)state, ddl_file);

		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br_rebirth");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"topFive");
		DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_top5);

	}

	/*	ImGui::Dummy(ImVec2(0.0f, 3.0f));*/
	ImGui::SliderInt("##KILLS", &i_kills, 1, 9999999, "Kills %d");
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Kills"), ImVec2(-1, 30)))
	{
		char context[255];
		char state[255];

		__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

		DDL_GetRootState((__int64)state, ddl_file);

		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br_rebirth");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"kills");

		DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_kills);
	}

	/*ImGui::Dummy(ImVec2(0.0f, 3.0f));*/
	ImGui::SliderInt("##DEATHS", &i_deaths, 1, 9999999, "Deaths %d");
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Deaths"), ImVec2(-1, 30)))
	{
		char context[255];
		char state[255];

		__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

		DDL_GetRootState((__int64)state, ddl_file);

		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br_rebirth");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"deaths");

		DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_deaths);
	}
}

void BRTab()
{
	ImGui::TextDisabled(xorstr_(" Step 1. Change the number for Stats and hit Set.\n Step 2. Go into a game start and kill yourself.\n Make sure you kill yourself after the Pregamelobby!"));
	ImGui::SliderInt("##BRSOCRE", &i_score, 1, 5555555555, "Score %d");
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Score"), ImVec2(-1, 30)))
	{
		char context[255];
		char state[255];

		__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

		DDL_GetRootState((__int64)state, ddl_file);

		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"score");

		DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_score);
	}

	ImGui::SliderInt("##BRGAMES", &i_games, 1, 5555555555, "Games Played %d");
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Games"), ImVec2(-1, 30)))
	{
		char context[255];
		char state[255];

		__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

		DDL_GetRootState((__int64)state, ddl_file);

		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"gamesPlayed");

		DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_games);
	}
	/*ImGui::SliderInt("##BRTIME", &i_timeplayed, 1, 5555555555, "Time Played %d");
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Time"), ImVec2(-1, 30)))
	{
		char context[255];
		char state[255];

		__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

		DDL_GetRootState((__int64)state, ddl_file);

		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"timePlayed");

		DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_timeplayed);
	}*/

	ImGui::SliderInt("##BRWINS", &i_wins, 1, 5555555555, "Wins %d");
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Wins"), ImVec2(-1, 30)))
	{
		char context[255];
		char state[255];

		__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

		DDL_GetRootState((__int64)state, ddl_file);

		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"wins");

		DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_wins);
	}

	ImGui::SliderInt("##BRTOP5", &i_top5, 1, 5555555555, "Top 5 %d");
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Top5"), ImVec2(-1, 30)))
	{
		char context[255];
		char state[255];

		__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

		DDL_GetRootState((__int64)state, ddl_file);

		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"topFive");
		DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_top5);

	}

	ImGui::SliderInt("##BRKILLS", &i_kills, 1, 5555555555, "Kills %d");
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Kills"), ImVec2(-1, 30)))
	{
		char context[255];
		char state[255];

		__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

		DDL_GetRootState((__int64)state, ddl_file);

		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"kills");

		DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_kills);
	}

	ImGui::SliderInt("##BRDEATHS", &i_deaths, 1, 5555555555, "Deaths %d");
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Deaths"), ImVec2(-1, 30)))
	{
		char context[255];
		char state[255];

		__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

		DDL_GetRootState((__int64)state, ddl_file);

		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"deaths");

		DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_deaths);
	}
	ImGui::SliderInt("##BRDOWNS", &i_downs, 1, 5555555555, "Downs %d");
	ImGui::SameLine();
	if (ImGui::Button(xorstr_("Set Downs"), ImVec2(-1, 30)))
	{
		char context[255];
		char state[255];

		__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

		DDL_GetRootState((__int64)state, ddl_file);

		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
		DDL_MoveToName((__int64)state, (__int64)state, (__int64)"downs");

		DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_downs);
	}
}

void cMenu::DrawMenu()
{
	static float rainbow;
	rainbow += 0.0030f; //0.0001f
	if (rainbow > 1.f)
		rainbow = 0.f;

	auto rgb = ImColor::HSV(rainbow, 1.f, 1.f, 0.8f);     // Rainbow Items
	auto rgb_a = ImColor::HSV(rainbow, 1.f, 1.f, 0.9f);   // Selected / Hovered Items
	auto rgb_b = ImColor::HSV(rainbow, 1.f, 1.f, 0.7f);   // Pressed Items

	ImVec4* colors = ImGui::GetStyle().Colors;
	/*ImGui::SetNextWindowSize({ 425, 440 });*/
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
	colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_Button] = rgb; // ImColor(255, 123, 0, 255);
	colors[ImGuiCol_ButtonHovered] = rgb; // ImColor(255, 159, 50, 255);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
	colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_Tab] = rgb; // ImColor(255, 123, 0, 255);
	colors[ImGuiCol_TabHovered] = rgb; // ImColor(255, 159, 50, 255);
	colors[ImGuiCol_TabHovered] = rgb; // ImColor(255, 123, 0, 255);
	colors[ImGuiCol_TabActive] = rgb; // ImColor(255, 123, 0, 255);
	colors[ImGuiCol_PlotLines] = rgb; // ImColor(255, 123, 0, 255);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);

	ImGuiStyle& style = ImGui::GetStyle();
	style.ItemSpacing = ImVec2(6.00f, 6.00f);
	style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
	style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
	style.IndentSpacing = 25;
	style.ScrollbarSize = 15;
	style.GrabMinSize = 10;
	style.WindowBorderSize = 1;
	style.ChildBorderSize = 1;
	style.PopupBorderSize = 1;
	style.FrameBorderSize = 1;
	style.TabBorderSize = 1;
	style.WindowRounding = 7;
	style.ChildRounding = 4;
	style.FrameRounding = 3;
	style.PopupRounding = 4;
	style.ScrollbarRounding = 9;
	style.GrabRounding = 3;
	style.TabRounding = 4;
	style.WindowTitleAlign = ImVec2(0.5, 0.5);

	ImGuiIO& io = ImGui::GetIO();
	ImFont* main_font = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Tahoma.ttf", 11.0f);

	if (ImGui::Begin("AIO TOOL", &g_vars->msettings.b_menuEnable, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoScrollbar))

	if (ImGui::BeginTabBar("tabs"))
	{

		if (ImGui::BeginTabItem("Main"))
		{
			MainTab();
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Visual"))
		{
			EhmTab();
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Exploits"))
		{
			VisualsTab();
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Battle Royale"))
		{
			BRTab();
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Rebirth Stats"))
		{
			RebirthTab();
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::EndTabItem();
		}
		
		ImGui::EndTabBar();

	}
}