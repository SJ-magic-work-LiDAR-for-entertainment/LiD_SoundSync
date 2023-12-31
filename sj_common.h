/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include <stdio.h>

#include <ofMain.h>
#include <ofxGui.h>

/************************************************************
************************************************************/
#define ERROR_MSG(); printf("Error in %s:%d\n", __FILE__, __LINE__);

/************************************************************
************************************************************/
enum{
	MAIN_WINDOW_W = 1920,
	MAIN_WINDOW_H = 1080,
};

enum{
	BUF_SIZE_S = 500,
	BUF_SIZE_M = 1000,
	BUF_SIZE_L = 6000,
};

enum{
	AUDIO_BUF_SIZE = 512,
	AUDIO_BUFFERS = 2,			// 使われてないっぽい
	AUDIO_SAMPLERATE = 44100,
};

/************************************************************
************************************************************/

/**************************************************
**************************************************/
class GUI_GLOBAL{
private:
	/****************************************
	****************************************/
	
public:
	/****************************************
	****************************************/
	void setup(string GuiName, string FileName = "gui.xml", float x = 10, float y = 10);
	
	ofxGuiGroup Group_Audio;
		ofxToggle b_Audio_Start;
		ofxToggle b_Audio_Stop;
		ofxToggle b_Audio_Reset;
		
	ofxGuiGroup Group_FFT;
		ofxFloatSlider FFT__SoftGain;
		ofxFloatSlider FFT__k_smooth;
		ofxFloatSlider FFT__dt_smooth_2_N;
		ofxFloatSlider FFT__dt_smooth_2_A;
		ofxToggle FFT__b_HanningWindow;
		ofxFloatSlider FFT__Afilter_0dB_at_Hz;
		
	ofxGuiGroup Group_ArtSin;
		ofxFloatSlider ArtSin_Band_min__N;
		ofxFloatSlider ArtSin_Band_max__N;
		ofxFloatSlider ArtSin_Band_min__A;
		ofxFloatSlider ArtSin_Band_max__A;
		ofxFloatSlider ArtSin_PhaseMap_k;
		ofxToggle b_ArtSin_PhaseMap_MoreDynamic_N;
		ofxToggle b_ArtSin_PhaseMap_MoreDynamic_A;
		ofxToggle b_ArtSin_abs;
		ofxToggle b_TukeyWindow_artSin;
		ofxFloatSlider Tukey_alpha;
		
	ofxGuiGroup Group_DrawFFT;
		ofxFloatSlider DrawFFT_ContentsCombination_id;
		
	ofxGuiGroup Group_DrawArtSin;
		ofxToggle b_DrawArtSin_Overlay;
		ofxToggle b_DrawArtSin_MaskUpper;
		ofxToggle b_DrawArtSin_MaskLower;
		ofxFloatSlider DrawArtSin_ScreenHeightOfOne;
		ofxColorSlider DrawArtSin_col__N;
		ofxColorSlider DrawArtSin_col__A;
		ofxColorSlider DrawArtSin_col__MixDown;
		
	ofxGuiGroup Group_DrawEnergy;
		ofxColorSlider DrawEnergy_col;
		ofxFloatSlider DrawEnergy_lpf;
		ofxFloatSlider DrawEnergy_devide;
		ofxFloatSlider DrawEnergy_th[3];
		ofxFloatSlider DrawEnergy_cut_change_interval;
		
	ofxGuiGroup Group_misc;
		ofxToggle b_reload_gui_setting;
		ofxFloatSlider col_ClearFbo;
		
	ofxGuiGroup Group_unity;
		ofxToggle b_send_udp;
		ofxFloatSlider unity_sound_wave_h;
		ofxFloatSlider unity_sound_wave_space;
		ofxVec3Slider unity_sound_wave_center;
		ofxFloatSlider unity_sound_wave_type;
	
	ofxPanel gui;
	
	bool b_Disp = false;
};

/************************************************************
************************************************************/
template <typename T>
T sj_max(T a, T b)
{
	if(a < b)	return b;
	else		return a;
}

template <typename T>
T sj_min(T a, T b)
{
	if(b < a)	return b;
	else		return a;
}

/************************************************************
************************************************************/
double LPF(double LastVal, double NewVal, double Alpha_dt, double dt);
double LPF(double LastVal, double NewVal, double Alpha);

bool checkIf_ContentsExist(char* ret, char* buf);
void Align_StringOfData(string& s);
void print_separatoin();
void ClearFbo(ofFbo& fbo);

float toRad(float val);
float toDeg(float val);

float get_RawVal_top_of_artsin_window(float window_H, float ScreenHeightOfOne);

/************************************************************
************************************************************/
extern GUI_GLOBAL* Gui_Global;

extern FILE* fp_Log;

extern int GPIO_0;
extern int GPIO_1;

extern const float _PI;

/************************************************************
************************************************************/

