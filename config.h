#ifndef CONFIG_H_
#define CONFIG_H_

// Path to proton
static const char *PROTON_PATH = "~/.steam/root/compatibilitytools.d/Proton-7.0rc6-GE-1/proton";

// Path for log files
static const char *CD_PATH = "/tmp";

#define DXVK_STATE_CACHE_PATH "/mnt/Dump/DXVK_CACHE"

#define STEAM_COMPAT_DATA_PATH "/mnt/Dump/.proton"

#define STEAM_COMPAT_CLIENT_INSTALL_PATH "~/.local/share/Steam"

#define VK_ICD_FILENAMES "/usr/share/vulkan/icd.d/nvidia_icd.json"

// Size of args array
#define EXTRA_ARGS_SIZE 5

// Extra args for creating the launch file
static const char *extra_args[EXTRA_ARGS_SIZE] = {
    "WINEESYNC=1",
    "DXVK_STATE_CACHE_PATH=" DXVK_STATE_CACHE_PATH,
    "VK_ICD_FILENAMES=" VK_ICD_FILENAMES,
    "STEAM_COMPAT_CLIENT_INSTALL_PATH=" STEAM_COMPAT_CLIENT_INSTALL_PATH,
    "STEAM_COMPAT_DATA_PATH=" STEAM_COMPAT_DATA_PATH,
};

#endif // CONFIG_H_
