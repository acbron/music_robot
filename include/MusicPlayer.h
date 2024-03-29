/*!
 * \file MusicPlay.h
 *
 * \brief 用于mp3音乐的解码及播放
 *
 * 用与解码mp3音乐，及播放。该类改自libmad库示例代码。
 *
 *
 */

#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/mman.h>


#include <string.h>
#include<fcntl.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <alsa/asoundlib.h>

# include <mad.h>

class MusicPlayer{
	public:
		//!构造函数
		MusicPlayer();

		//!析构函数
		~MusicPlayer();
		
		//!音乐播放函数
		/*!
		 * \brief 音乐播放函数
		 * 
		 * 选好参数，调用该函数播放音乐
		 *
		 * \param musicName 音乐名及地址（如"./music/a.mp3"）
		 * \param diviceName 设备名（如"default"、"hw:2,0"）
		 *
		 * \retval 0 运行正确
		 * \retval 1 设备打开失败
		 * \retval 2 fastat失败
		 * \retval 3 音乐停止
		 * \retval 4 pcm数据设置失败
		 * \retval 5 munmap为-1
		 *
		 */
		int playMusic( char * musicName, char *diviceName, int sampleRate, int channels);

		static snd_pcm_t * handle;              //< PCI设备句柄

		//!pcm缓冲区初始化
		void pcmBufferInit(int samples); 

		//!获取pcm缓冲区指针
		short * getPcmBuffer();

		//!获取pcm缓冲区是否已满信息
		/*!
		 * \brief 获取pcm缓冲区是否已满信息
		 *
		 * 获取pcm缓冲区是否已满信息
		 *
		 * \retval false 未满
		 * \retval true 已满
		 *
		 */
		bool getIsPcmBufferFull();

		/*!
		 * \brief 变量isPcmBufferFull的set函数
		 *
		 * 只是在调用getIsPcmBufferFull
		 *
		 */
		void setIsPcmBufferFull( bool isFull );

		/*
		 * \brief 设置音乐播放与停止
		 *
		 * 设置音乐的播放与停止
		 *
		 * \param isPlay 值为true正在播放,值为false播放停止
		 *
		 */
		void setIsPlay( bool isPlay );

	private:

		snd_pcm_hw_params_t*   params;   //< 硬件信息和PCM流配置
		char * diviceName;               //< 设备id(如"hw:2,0")
		static short * pcmBuffer;        //< pcm缓冲区
		static int sampleNum;            //< pcm缓冲区大小
		static int sampleCount;          //< pcm缓冲区计数
		static bool isPcmBufferFull;     //< 标记pcm缓冲区是否已满
		static bool isPlay;              //< 标记音乐状态
		
		/*
		 * This is a private message structure. A generic pointer to this structure
		 * is passed to each of the callback functions. Put here any data you need
		 * to access from within the callbacks.
		 */
		struct buffer {
			unsigned char const *start;
			unsigned long length;
		};

		int set_pcm(int sampleRate, int channels);
		static enum mad_flow input(void *data,struct mad_stream *stream);
		static inline signed int scale(mad_fixed_t sample);

		/*
		 * This is the output callback function. It is called after each frame of
		 * MPEG audio data has been completely decoded. The purpose of this callback
		 * is to output (or play) the decoded PCM audio.
		 */
		static enum mad_flow output(void *data, struct mad_header const *header, struct mad_pcm *pcm);

		/*
		 * This is the error callback function. It is called whenever a decoding
		 * error occurs. The error is indicated by stream->error; the list of
		 * possible MAD_ERROR_* errors can be found in the mad.h (or stream.h)
		 * header file.
		 */
		static enum mad_flow error(void *data, struct mad_stream *stream, struct mad_frame *frame);

		/*
		 * This is the function called by main() above to perform all the decoding.
		 * It instantiates a decoder object and configures it with the input,
		 * output, and error callback functions above. A single call to
		 * mad_decoder_run() continues until a callback function returns
		 * MAD_FLOW_STOP (to stop decoding) or MAD_FLOW_BREAK (to stop decoding and
		 * signal an error).
		 */
		static
			int decode(unsigned char const *start, unsigned long length);


};

#endif
