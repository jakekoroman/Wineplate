#ifndef CONFIG_H_
#define CONFIG_H_


// Path to proton
static const char *PROTON_PATH = "/home/jake/.steam/root/compatibilitytools.d/Proton-7.0rc6-GE-1/proton";

// path for log files
static const char *CD_PATH = "/tmp";

// Size of args array
#define EXTRA_ARGS_SIZE 4

#define DXVK_STATE_CACHE_PATH "/mnt/Dump/DXVK_CACHE"

#define STEAM_COMPAT_DATA_PATH "/mnt/Dump/.proton"

#define STEAM_COMPAT_CLIENT_INSTALL_PATH "/home/jake/.local/share/Steam"


// Extra args for creating the launch file
static const char *extra_args[EXTRA_ARGS_SIZE] = {
    "WINEESYNC=1",
    "DXVK_STATE_CACHE_PATH=" DXVK_STATE_CACHE_PATH,
    "STEAM_COMPAT_DATA_PATH=" STEAM_COMPAT_DATA_PATH,
    "STEAM_COMPAT_CLIENT_INSTALL_PATH=" STEAM_COMPAT_CLIENT_INSTALL_PATH,
};


#endif // CONFIG_H_
