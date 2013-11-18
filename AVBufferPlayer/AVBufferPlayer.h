
#import <AVFoundation/AVFoundation.h>

/*
 * Uses AVAudioPlayer to play a buffer of waveform data that you give it.
 * You can use this for simple non-realtime sound synthesis.
 */
@interface AVBufferPlayer : NSObject {
@private
    SInt8 *wavBuffer; // buffer with WAV header added
}

/*
 * Initializes the AVBufferPlayer.
 *
 * Note: Currently all output is 44100 Hz, 16 bit, mono.
 *
 * @param buffer A buffer of floating point values between -1.0f and 1.0f that
 *        represent your waveform. The caller is responsible for freeing this
 *        buffer, which can be done immediately after this function returns.
 * @param frames The number of frames in the buffer. A frame is a single sample
 *        so the number of bytes in the buffer is 4 times the number of frames.
 */
- (id)initWithBuffer:(float *)buffer frames:(int)frames;

/*
 * Initializes the AVBufferPlayer.
 *
 * Note: Currently all output is 44100 Hz, 16 bit.
 *
 * @param buffer A buffer of floating point values between -1.0f and 1.0f that
 *        represent your waveform. The caller is responsible for freeing this
 *        buffer, which can be done immediately after this function returns.
 * @param frames The number of frames in the buffer. A frame is a single sample
 *        so the number of bytes in the buffer is 4 times the number of frames
 *	  for mono, or 8 times the number of frames for stereo
 *
 * @param channels The number of channels in the input buffer. Must be 1 (mono)
 *	  or 2 (stereo)
 */
- (id)initWithBuffer:(float *)buffer frames:(int)frames channels:(int) channels;

/*
 * Plays the sound.
 */
- (void)play;

/*
 * Stops the sound.
 */
- (void)stop;

@end
