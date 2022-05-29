#ifndef CONFIG_H_
#define CONFIG_H_

// Path to the wine version you wish to use
static const char *WINE_PATH = "wine";

// Path for log files
static const char *CD_PATH = "/tmp";

#define DXVK_STATE_CACHE_PATH "/mnt/Dump/DXVK_CACHE"

#define VK_ICD_FILENAMES "/usr/share/vulkan/icd.d/nvidia_icd.json"

#define WINEPREFIX "/mnt/Dump/.gamer"

// Size of args array
#define EXTRA_ARGS_SIZE 4

// Extra args for creating the launch file
static const char *extra_args[EXTRA_ARGS_SIZE] = {
    "WINEESYNC=1",
    "WINEPREFIX=" WINEPREFIX,
    "DXVK_STATE_CACHE_PATH=" DXVK_STATE_CACHE_PATH,
    "VK_ICD_FILENAMES=" VK_ICD_FILENAMES,
};

#endif // CONFIG_H_
