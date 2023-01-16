#pragma once
#include "../adventUtil/utils.h"
// result second day first half: 10310
class SecondDay : public Days{
    public:
        enum OPTIONS{
            ROCK = 1,
            PAPER,
            SCRISSORS
        };
        enum RESULTS{
            LOOSE,
            DRAWN = 3,
            WIN = 6
        };

        SecondDay()
        {

        };
        ~SecondDay(){};
        void doWork() override;
        void getInput(string& filePath) override;
        multimap<string,string> getResults()const ;
    private:
        void printResults() override;
        void encryptingStrategy();
        void decryptingStrategy();
        void calculateSummary();
        int mEncryptedSummary;
        int mDecryptedSummary;
        map<int, string> mOponentProps{ {ROCK, "A"},
                                    {PAPER, "B"},
                                    {SCRISSORS, "C"}
                                    };

        map<string, int> mEncryptedProps{ {"X", ROCK},
                                    {"Y", PAPER},
                                    {"Z", SCRISSORS}
                                    };
        map<string, int> mDecryptedProps{ {"X", ROCK},
                                    {"Y", PAPER},
                                    {"Z", SCRISSORS}
                                    };

        multimap<string,string> mResults;
};
