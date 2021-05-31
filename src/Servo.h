class Servo{
private:
    int pwm_freq;
    int pwm_channel;
    int pwm_resolution;
    int pwm_pinNum;
    int pwm_offset;
    int pwm_steps;
public:
    Servo(int pwmPinNum, int pwmFreq, int pwmChannel, int pwmResuoltion);
    bool goToPosition(int position);
    void goHome();
    void goMax();
};