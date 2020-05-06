/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __CONFIGACTIVITY_H__
#define __CONFIGACTIVITY_H__


#include "app/Activity.h"
#include "entry/EasyUIContext.h"

#include "uart/ProtocolData.h"
#include "uart/ProtocolParser.h"

#include "utils/Log.h"
#include "control/ZKDigitalClock.h"
#include "control/ZKButton.h"
#include "control/ZKCircleBar.h"
#include "control/ZKDiagram.h"
#include "control/ZKListView.h"
#include "control/ZKPointer.h"
#include "control/ZKQRCode.h"
#include "control/ZKTextView.h"
#include "control/ZKSeekBar.h"
#include "control/ZKEditText.h"
#include "control/ZKVideoView.h"
#include "window/ZKSlideWindow.h"

/*TAG:Macro宏ID*/
#define ID_CONFIG_TextView_credits_scroll    50011
#define ID_CONFIG_TextView_credits    50010
#define ID_CONFIG_Button_about_back    20005
#define ID_CONFIG_TextView4    50009
#define ID_CONFIG_Window_about    110004
#define ID_CONFIG_TextView_version_hw    50008
#define ID_CONFIG_TextView_version_fw    50007
#define ID_CONFIG_TextView_hw    50006
#define ID_CONFIG_TextView_fw    50005
#define ID_CONFIG_Button_version_back    20004
#define ID_CONFIG_TextView3    50004
#define ID_CONFIG_Window_version    110003
#define ID_CONFIG_TextView2    50003
#define ID_CONFIG_TextView1    50002
#define ID_CONFIG_Button_backLight_back    20003
#define ID_CONFIG_Window_backLight    110002
#define ID_CONFIG_SeekBar_backLight    91001
#define ID_CONFIG_Button_Scheck_start    20002
#define ID_CONFIG_Button_Scheck_close    20001
#define ID_CONFIG_TextView_Scheck    50001
#define ID_CONFIG_Window_Scheck    110001
#define ID_CONFIG_ListView_config    80001
#define ID_CONFIG_sys_back   100
/*TAG:Macro宏ID END*/

class configActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    configActivity();
    virtual ~configActivity();

    /**
     * 注册定时器
     */
	void registerUserTimer(int id, int time);
	/**
	 * 取消定时器
	 */
	void unregisterUserTimer(int id);
	/**
	 * 重置定时器
	 */
	void resetUserTimer(int id, int time);

protected:
    /*TAG:PROTECTED_FUNCTION*/
    virtual const char* getAppName() const;
    virtual void onCreate();
    virtual void onClick(ZKBase *pBase);
    virtual void onResume();
    virtual void onPause();
    virtual void onIntent(const Intent *intentPtr);
    virtual bool onTimer(int id);

    virtual void onProgressChanged(ZKSeekBar *pSeekBar, int progress);

    virtual int getListItemCount(const ZKListView *pListView) const;
    virtual void obtainListItemData(ZKListView *pListView, ZKListView::ZKListItem *pListItem, int index);
    virtual void onItemClick(ZKListView *pListView, int index, int subItemIndex);

    virtual void onSlideItemClick(ZKSlideWindow *pSlideWindow, int index);

    virtual bool onTouchEvent(const MotionEvent &ev);

    virtual void onTextChanged(ZKTextView *pTextView, const string &text);

    void rigesterActivityTimer();

    virtual void onVideoPlayerMessage(ZKVideoView *pVideoView, int msg);
    void videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex);
    void startVideoLoopPlayback();
    void stopVideoLoopPlayback();
    bool parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList);
    int removeCharFromString(string& nString, char c);


private:
    /*TAG:PRIVATE_VARIABLE*/
    int mVideoLoopIndex;
    int mVideoLoopErrorCount;

};

#endif