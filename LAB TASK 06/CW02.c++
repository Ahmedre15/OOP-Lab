#include <iostream>
using namespace std;

class MediaFile {
protected:
    string filePath;
    double size;
public:
    MediaFile(string path, double s) : filePath(path), size(s) {}
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile {
protected:
    int resolutionX, resolutionY;
public:
    VisualMedia(string path, double s, int x, int y) : MediaFile(path, s), resolutionX(x), resolutionY(y) {}
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;
public:
    AudioMedia(string path, double s, int rate) : MediaFile(path, s), sampleRate(rate) {}
};

class ImageFile : public VisualMedia {
public:
    ImageFile(string path, double s, int x, int y) : MediaFile(path, s), VisualMedia(path, s, x, y) {}
    void play() override { cout << "Displaying Image: " << filePath << endl; }
    void stop() override { cout << "Closing Image: " << filePath << endl; }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string path, double s, int rate) : MediaFile(path, s), AudioMedia(path, s, rate) {}
    void play() override { cout << "Playing Audio: " << filePath << endl; }
    void stop() override { cout << "Stopping Audio: " << filePath << endl; }
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, double s, int x, int y, int rate) 
        : MediaFile(path, s), VisualMedia(path, s, x, y), AudioMedia(path, s, rate) {}
    void play() override { cout << "Playing Video: " << filePath << endl; }
    void stop() override { cout << "Stopping Video: " << filePath << endl; }
};

int main() {
    MediaFile* media[] = {
        new ImageFile("image.jpg", 2.5, 1920, 1080),
        new AudioFile("audio.mp3", 3.2, 44100),
        new VideoFile("video.mp4", 50.0, 1920, 1080, 48000)
    };
    
    for (int i = 0; i < 3; i++) {
        media[i]->play();
        media[i]->stop();
        delete media[i];
    }
    return 0;
}
