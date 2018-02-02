#include <string>
#include <sys/ioctl.h>


class TImager {
    private:
        std::string deviceName;
        int fd;
        std::string errorString;


    bool xioctl(int request, void *arg, std::string errStr) {
        int r;
        do r = ioctl (fd, request, arg);
        while (-1 == r && EINTR == errno);
        if (-1 == r) {
            errorString = errStr;
            return false;
        }
        return true;
    }

    bool OpenDevice() {
        fd = open(deviceName.c_str(), O_RDWR);
        if (fd == -1) {
            errorString = std::string("Cannot open WebCam: ") + deviceName;
            return false;
        }
        return true;
    }


    GetModeList() {
        struct v4l2_capability caps = {0};
        if (xioctl(VIDIOC_QUERYCAP, &caps, std::string("Bad Querying Capabilites request for WebCam: ") + deviceName)) {
        } else {
        }
    }





    public:
    TImager(std::string device)
        : device(device) {
    }

    ~TImager() {
    }

    void Capture() {
    }
}
