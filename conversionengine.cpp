#include "conversionengine.h"

#include <string>
#include <cmath>

conversionEngine::conversionEngine()
{

}


// Length


void conversionEngine::fromCM(float cm){
    mm = cm*10;
}
void conversionEngine::fromFt(float ft){
    mm = ft*304.8;
}
void conversionEngine::fromIn(float in){
    mm = in*25.4;
}
void conversionEngine::fromKm(float km){
    mm = km*1000000;
}
void conversionEngine::fromM(float m){
    mm = m*1000;
}
void conversionEngine::fromMi(float mi){
    mm = mi*1609344;
}
void conversionEngine::fromMM(float milim){
    mm = milim;
}
void conversionEngine::fromYd(float yd){
    mm = yd*914.4;
}


float conversionEngine::getCm(){
    float cm = mm*0.1;
    return cm;
}
float conversionEngine::getFt() {
    float ft = mm*0.0032808399;
    return ft;
}
float conversionEngine::getIn() {
    float in = mm*0.0393700787;
    return in;
}
float conversionEngine::getKm() {
    float km = mm*0.000001;
    return km;
}
float conversionEngine::getM() {
    float m = mm*0.001;
    return m;
}
float conversionEngine::getMi() {
    float mi = mm*0.0000006213712;
    return mi;
}
float conversionEngine::getMM(){
    return mm;
}
float conversionEngine::getYd() {
    float yd = mm*0.0010936133;
    return yd;
}

//Time

void conversionEngine::fromDays(float days){
    sec = days*86400;
}
void conversionEngine::fromHours(float hrs){
    sec = hrs*3600;
}
void conversionEngine::fromuS(float us){
    sec = us*0.000001;
}
void conversionEngine::fromMS(float ms){
    sec = ms*0.001;
}
void conversionEngine::fromMin(float min){
    sec = min*60;
}
void conversionEngine::fromNS(float ns){
    sec = ns/1000000000;
}
void conversionEngine::fromSec(float secs){
    sec = secs;
}
void conversionEngine::fromWeeks(float weeks){
    sec = weeks*604800;
}
void conversionEngine::fromYears(float years){
    sec = years*31536000;
}

float conversionEngine::getDays(){
    float days = sec/86400;
    return days;
}
float conversionEngine::getHours(){
    float hours = sec/3600;
    return hours;
}
float conversionEngine::getuS(){
    float us = sec*1000000;
    return us;
}
float conversionEngine::getMS(){
    float ms = sec*1000;
    return ms;
}
float conversionEngine::getMin(){
    float min = sec/60;
    return min;
}
float conversionEngine::getNS(){
    float ns = sec*1000000000;
    return ns;
}
float conversionEngine::getSec(){
    return sec;
}
float conversionEngine::getWeeks(){
    float weeks = sec/604800;
    return weeks;
}
float conversionEngine::getYears(){
    float years = sec/31536000;
    return years;
}

//Temperature

void conversionEngine::fromF(float f){
    f = f-32;
    c = f/1.8;
}
void conversionEngine::fromC(float C){
    c = C;
}
void conversionEngine::fromK(float k){
    c = k-273.15;
}

float conversionEngine::getC(){
    return c;
}
float conversionEngine::getF(){
    c = c*1.8;
    float f = c+32;
    return f;
}
float conversionEngine::getK(){
    float k = c+273.15;
    return k;
}

//Volume
void conversionEngine::fromTSP(float tsp){
    gal = tsp*0.0013208602;
}
void conversionEngine::fromTBSP(float tbsp){
    gal = tbsp*0.0039625807;
}
void conversionEngine::fromGAL(float Gal){
    gal = Gal;
}
void conversionEngine::fromOZ(float oz){
    gal = oz*0.0078125;
}
void conversionEngine::fromCUPS(float cups){
    gal = cups*0.066043013;
}

float conversionEngine::getTSP(){
    float tsp = gal*757.0823568;
    return tsp;
}
float conversionEngine::getTBSP(){
    float tbsp = gal*252.3607856;
    return tbsp;
}
float conversionEngine::getGAL(){
    return gal;
}
float conversionEngine::getOZ(){
    float oz = gal*128;
    return oz;
}
float conversionEngine::getCUPS(){
    float cups = gal*15.141647136;
    return cups;
}

//Data

void conversionEngine::frombits(float bit){
    bits = bit;
}
void conversionEngine::frombytes(float bytes){
    bits = bytes*8;
}
void conversionEngine::fromkb(float kb){
    bits = kb*1024;
}
void conversionEngine::fromkB(float kB){
    bits = kB*8192;
}
void conversionEngine::fromMb(float Mb){
    bits = Mb*1048576;
}
void conversionEngine::fromMB(float MB){
    bits = MB*8388608;
}
void conversionEngine::fromGb(float Gb){
    bits = Gb*1073741824;
}
void conversionEngine::fromGB(float GB){
    bits = GB*8589934592;
}
void conversionEngine::fromTb(float Tb){
    bits = Tb*1099511627776;
}
void conversionEngine::fromTB(float TB){
    bits = TB*8796093022208;
}

float conversionEngine::getBits(){
    return bits;
}
float conversionEngine::getBytes(){
    float bytes = bits/8;
    return bytes;
}
float conversionEngine::getkb(){
    float kb = bits/1024;
    return kb;
}
float conversionEngine::getkB(){
    float kB = bits/8192;
    return kB;
}
float conversionEngine::getMb(){
    float Mb = bits/1048576;
    return Mb;
}
float conversionEngine::getMB(){
    float MB = bits/8388608;
    return MB;
}
float conversionEngine::getGb(){
    float Gb = bits/1073741824;
    return Gb;
}
float conversionEngine::getGB(){
    float GB = bits/8589934592;
    return GB;
}
float conversionEngine::getTb(){
    float Tb = bits/1099511627776;
    return Tb;
}
float conversionEngine::getTB(){
    float TB = bits/8796093022208;
    return TB;
}

//Base
void conversionEngine::fromDecimal(int decimal){
    dec = decimal;
}
void conversionEngine::fromBin(int bin){
    std::string s = std::to_string(bin);
    std::string sbw;
    int l = s.length();
    for(int i=l-1;i>=0;i--){
        sbw = sbw + s[i];
    }
    int decimal=0;
    for(int i = 0; i<=l;i++){
        if(sbw[i]=='1'){
            decimal = decimal+pow(2.0, i);
        }
    }
    dec = decimal;
}
void conversionEngine::fromHex(std::string hex){
    std::string sbw;
    int l = hex.length();
    for(int i=l-1; i>=0; i--){
        sbw = sbw + hex[i];
    }
    int decimal=0;
    for(int i=0; i<=l; i++){
        if(sbw[i]=='f'){
            decimal = decimal + pow(15.0, i);
        }else if(sbw[i]=='e'){
            decimal = decimal + pow(14.0, i);
        }else if(sbw[i]=='d'){
            decimal = decimal + pow(13.0, i);
        }else if(sbw[i]=='c'){
            decimal = decimal + pow(12.0, i);
        }else if(sbw[i]=='b'){
            decimal = decimal + pow(11.0, i);
        }else if(sbw[i]=='a'){
            decimal = decimal + pow(10.0, i);
        }else{
            decimal = decimal + pow(sbw[i], i);
        }
    }
    dec = decimal;
}
void conversionEngine::fromOctal(int oct){
    std::string s = std::to_string(oct);
    std::string sbw;
    int l = s.length();
    for(int i=l-1; i<=l; i--){
        sbw = sbw + s[i];
    }
    int decimal = 0;
    for(int i = 0; i<=l; i++){
        decimal = decimal + pow(sbw[i], i);
    }
}

int conversionEngine::getDec(){
    return dec;
}
int conversionEngine::getBin(){
    int binary = 0;
    int decimal = dec;
    if(decimal >= 512){
        decimal = decimal - 512;
        binary = binary + 1000000000;
    }
    if(decimal >= 256){
        decimal = decimal - 256;
        binary = binary + 100000000;
    }
    if(decimal >= 128){
        decimal = decimal -128;
        binary = binary + 10000000;
    }
    if(decimal >= 64){
        decimal = decimal - 64;
        binary = binary + 1000000;
    }
    if(decimal >= 32){
        decimal = decimal -32;
        binary = binary + 100000;
    }
    if(decimal >= 16){
        decimal = decimal - 16;
        binary = binary + 10000;
    }
    if(decimal >= 8){
        decimal = decimal - 8;
        binary = binary + 1000;
    }
    if(decimal >= 4){
        decimal = decimal - 4;
        binary = binary + 100;
    }
    if(decimal >= 2){
        decimal = decimal - 2;
        binary = binary + 10;
    }
    if(decimal >= 1){
        decimal = decimal -1;
        binary = binary + 1;
    }
    return binary;
}
std::string conversionEngine::getHex(){
    std::string hex;
    return hex;
}
int conversionEngine::getOctal(){
    return dec;
}
