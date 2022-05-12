#include "investapiclient.h"
#include "marketdatastreamservice.h"

void tradesStreamCallBack(ServiceReply reply)
{
    std::cout << reply.ptr()->DebugString() << std::endl;
}

int main()
{    
    InvestApiClient tinkoffInvestClient("invest-public-api.tinkoff.ru:443", getenv("TOKEN"));

    //get reference to marketdata and orders service
    auto marketdatastream = std::dynamic_pointer_cast<MarketDataStream>(tinkoffInvestClient.service("marketdatastream"));

    //subscribe on British American Tobacco and Visa Inc. prices and start streaming
    marketdatastream->SubscribeLastPrice({"BBG004S68758", "BBG004730JJ5"}, tradesStreamCallBack);

    return 0;
}
