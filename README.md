    
    ...

    VideoCapture& vc = *VideoCapture::getInstance();
    vc.init(surface_width, surface_height, frameRate, videoFile.c_str(), AV_CODEC_ID_H264);

		while(game.isRunning()) {
			game.render();
			vc.encode(game.getSurface());
		}

		...

