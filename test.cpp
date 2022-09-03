#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "RGBAColor1.h"
#include "RGBAColor2.h"

bool someErrorOccurred = false;

bool representSameColor(const RGBAColor1& rgbaColor1, const RGBAColor2& rgbaColor2)
{
    return rgbaColor1.getRed() == rgbaColor2.getRed() && rgbaColor1.getGreen() == rgbaColor2.getGreen() && rgbaColor1.getBlue() == rgbaColor2.getBlue() && rgbaColor1.getAlpha() == rgbaColor2.getAlpha();
}

void printRgbaColor1(const RGBAColor1& rgbaColor1) {
    printf("R: %d, G: %d, B: %d, A: %d", rgbaColor1.getRed(), rgbaColor1.getGreen(), rgbaColor1.getBlue(), rgbaColor1.getAlpha());
}

void printRgbaColor2(const RGBAColor2& rgbaColor2) {
    printf("R: %d, G: %d, B: %d, A: %d", rgbaColor2.getRed(), rgbaColor2.getGreen(), rgbaColor2.getBlue(), rgbaColor2.getAlpha());
}

void compareAndWarnIfDifferent(const RGBAColor1& rgbaColor1, const RGBAColor2& rgbaColor2)
{
    if(!representSameColor(rgbaColor1, rgbaColor2)) {
        printf("don't represent same color;\nrgbaColor1: ");
        printRgbaColor1(rgbaColor1);
        printf("\nrgbaColor2: ");
        printRgbaColor2(rgbaColor2);
        printf("\n");
        someErrorOccurred = true;
    }
}

void initializeRNGSeed()
{
    srand(time(0));
}

uint8_t randomColorComponent() {
    uint16_t randomComponent = rand() % 256;
    return randomComponent;
}

int main()
{
    RGBAColor1 rgbaColor1;
    RGBAColor2 rgbaColor2;

    compareAndWarnIfDifferent(rgbaColor1, rgbaColor2);

    initializeRNGSeed();

    printf("testing getting and setters for some random colors...");

    size_t iteration = 0;
    size_t nOfTestSamples = 100000000;
    for(size_t i = 0 ; i < nOfTestSamples ; ++i) {
        iteration++;
        if(iteration % 10000000 == 0) {
            printf("iteration: %d\n", iteration);
            printf("(%lf %%)\n", ((double)iteration / nOfTestSamples) * 100);
        }

        uint8_t red = randomColorComponent();
        uint8_t green = randomColorComponent();
        uint8_t blue = randomColorComponent();
        uint8_t alpha = randomColorComponent();

        rgbaColor1.setRed(red);
        rgbaColor1.setGreen(green);
        rgbaColor1.setBlue(blue);
        rgbaColor1.setAlpha(alpha);

        rgbaColor2.setRed(red);
        rgbaColor2.setGreen(green);
        rgbaColor2.setBlue(blue);
        rgbaColor2.setAlpha(alpha);

        compareAndWarnIfDifferent(rgbaColor1, rgbaColor2);
    }

    if(someErrorOccurred) {
        printf("there is a least one difference");
    }

    printf("end.");
}