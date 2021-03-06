/* --------------------------------------------------------------------------------
 #
 #	4DPlugin.h
 #	source generated by 4D Plugin Wizard
 #	Project : Capture
 #	author : miyako
 #	2013/03/02
 #
 # --------------------------------------------------------------------------------*/

#import <QTKit/QTKit.h>

@interface ImageSnap : NSObject {
    
    QTCaptureSession                    *mCaptureSession;
    QTCaptureDeviceInput                *mCaptureDeviceInput;
    QTCaptureDecompressedVideoOutput    *mCaptureDecompressedVideoOutput;
    CVImageBufferRef                    mCurrentImageBuffer;
}

+(NSArray *)videoDevices;
+(QTCaptureDevice *)defaultVideoDevice;
+(QTCaptureDevice *)deviceForModel:(NSString *)model;

+(NSImage *)snapshotFromDevice:(QTCaptureDevice *)device;

-(id)init;
-(void)dealloc;

-(BOOL)startSession:(QTCaptureDevice *)device;
-(NSImage *)snapshot;
-(void)stopSession;

@end

typedef struct
{
	NSImage *image;
	QTCaptureDevice *device;
} SnapContext;

// --- Device
void CAPTURE_DEVICE_Get_default(sLONG_PTR *pResult, PackagePtr pParams);
void CAPTURE_DEVICE_LIST(sLONG_PTR *pResult, PackagePtr pParams);

// --- Snap
void CAPTURE_Snap(sLONG_PTR *pResult, PackagePtr pParams);
