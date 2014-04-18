#ifndef VIDEO_CAPTURE_HPP_
#define VIDEO_CAPTURE_HPP_

#include <stdio.h>
extern "C" {
#include <libavcodec/avcodec.h>
}

struct SDL_Surface;

class VideoCapture {
private:
	AVCodec* codec_;
    AVCodecContext* context_;
    AVPacket* pkt_;
    int frameIndex_;
    int gotOutput_;
    FILE *file_;
    AVFrame *rgbFrame_;
    AVFrame *yuvFrame_;
    bool initialzed_;
    static VideoCapture* instance_;
	VideoCapture();
public:
	virtual ~VideoCapture();
    void init(size_t width, size_t height, size_t fps, const char* filename, enum AVCodecID codec_id);
	void encode(SDL_Surface *surface);
	void close();

	static VideoCapture* getInstance() {
		if(instance_ == NULL)
			instance_ = new VideoCapture();

		return instance_;
	}
};

#endif

