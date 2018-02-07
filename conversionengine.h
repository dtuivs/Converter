#ifndef CONVERSIONENGINE_H
#define CONVERSIONENGINE_H

#include <string>
#include <cmath>


class conversionEngine
{
public:
    conversionEngine();

    //Length
    void fromCM(float cm);
    void fromFt(float ft);
    void fromIn(float in);
    void fromKm(float km);
    void fromM(float m);
    void fromMi(float mi);
    void fromMM(float milim);
    void fromYd(float yd);

    float getCm();
    float getFt();
    float getIn();
    float getKm();
    float getM();
    float getMi();
    float getMM();
    float getYd();

    //Time
    void fromDays(float days);
    void fromHours(float hrs);
    void fromuS(float us);
    void fromMS(float ms);
    void fromMin(float min);
    void fromNS(float ns);
    void fromSec(float secs);
    void fromWeeks(float weeks);
    void fromYears(float years);

    float getDays();
    float getHours();
    float getuS();
    float getMS();
    float getMin();
    float getNS();
    float getSec();
    float getWeeks();
    float getYears();

    //Temperature
    void fromF(float f);
    void fromC(float C);
    void fromK(float k);

    float getC();
    float getF();
    float getK();

    //Volume
    void fromTSP(float tsp);
    void fromTBSP(float tbsp);
    void fromGAL(float Gal);
    void fromOZ(float oz);
    void fromCUPS(float cups);

    float getTSP();
    float getTBSP();
    float getGAL();
    float getOZ();
    float getCUPS();

    //Data
    void frombits(float bit);
    void frombytes(float bytes);
    void fromkb(float kb);
    void fromkB(float kB);
    void fromMb(float Mb);
    void fromMB(float MB);
    void fromGb(float Gb);
    void fromGB(float GB);
    void fromTb(float Tb);
    void fromTB(float TB);

    float getBits();
    float getBytes();
    float getkb();
    float getkB();
    float getMb();
    float getMB();
    float getGb();
    float getGB();
    float getTb();
    float getTB();

    //Base
    void fromDecimal(int decimal);
    void fromBin(int bin);
    void fromHex(std::string hex);
    void fromOctal(int oct);

    int getDec();
    int getBin();
    std::string getHex();
    int getOctal();

private:
    float mm;
    float bits;
    float sec;
    float c;
    float gal;
    int dec;
};

#endif // CONVERSIONENGINE_H
