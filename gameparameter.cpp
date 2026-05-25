#include "common/macros.h"
#include "common/nnlogic.h"
#include "gameroot.h"
#include "context/context.h"
#include "Comm/ITableGame.h"
#include "utils/tarslog.h"
#include "message/sendclientmessage.h"
#include "logic/gamelogic/core/checkbegin.h"
#include "process/process.h"
#include "config/gameconfig.h"

namespace game
{
    namespace logic
    {
        namespace roomlogic
        {
            void GameParameter(void const *p, GameRoot *root)
            {
                PERFSTATS_ENTRY();
                __TRY__

                using namespace RoomSo;
                using namespace context;
                using namespace message;
                using namespace gamelogic;
                using namespace process;
                using namespace config;

                TGAME_GameParameter const *nnrs = static_cast<TGAME_GameParameter const *>(p);
                DLOG_TRACE("roomkey:" << root->cfg->getRoomKey()<<", --> TGAME_GameParameter_E" << ", data: " << printTars(*nnrs));

                root->cfg->setDalao(nnrs->iDalao);
                root->cfg->setClubId(nnrs->lClubId);
                root->cfg->setClubName(nnrs->sClubName);
                root->cfg->setRoomKey(nnrs->sRoomKey);
                root->cfg->setRoomName(nnrs->sRoomName);
                root->cfg->setSmallBlind(nnrs->iSmallBlind);
                root->cfg->setBigBlind(nnrs->iBigBlind);
                root->cfg->setAnte(nnrs->iAnte);
                root->cfg->setOptionTime(nnrs->iOptionTime);
                root->cfg->setAutoStartNum(nnrs->iAutoStartNum);
                root->cfg->setMinGold(nnrs->iMinGold);
                root->cfg->setMaxGold(nnrs->iMaxGold);
                root->cfg->setMaxSeatNum(nnrs->iMaxSeatNum);
                root->cfg->setInsure(nnrs->iInsure == 1 ? true : false);
                root->cfg->setGameType(nnrs->iGameType);
                root->cfg->setProfit(nnrs->iProfit);
                root->cfg->setGameTime(nnrs->iGameTime);
                root->cfg->setCreateTime(nnrs->lCreateTime);
                root->cfg->setBlind(nnrs->bBlind);
                root->cfg->setContral(nnrs->bContral);
                root->cfg->setCreatedId(nnrs->lCreatedId);
                root->cfg->setBetLimit(nnrs->bBetLimit);
                root->cfg->setHdCount(nnrs->iHdCount);
                root->cfg->setOpenSneak(nnrs->bSneak ? true: false);
                root->cfg->setMimi(nnrs->bMimi ? true: false);
                root->cfg->setShow(nnrs->bShow ? true: false);
                root->cfg->setPause(false);

                root->cfg->setMinBuyIn(nnrs->iMinBuyIn);
                root->cfg->setFeeLimit(nnrs->iFeeLimit);
                root->cfg->setFeeDynamic(nnrs->bFeeDynamic ? true : false);

                if((nnrs->iGameType >= 1 && nnrs->iGameType <= 3) || nnrs->iGameType == 7)
                {
                    root->cfg->setIsStart(false);
                }

                if (nnrs->iOptionTime > 0)
                {
                    root->cfg->setInitBetTime(1, nnrs->iOptionTime - 1);
                }

                root->cfg->setShortDeck(false);
                //设置是否是短牌玩法
                if (nnrs->iGameType == 3)
                {
                    root->cfg->setShortDeck(true);
                }

                // 临时
                root->cfg->setBlindNum(nnrs->iSmallBlind);
                root->cfg->setBlindLevel(nnrs->iBlindLevel);
                root->cfg->setMaxSeatByRoom(nnrs->iMaxSeatNum);
                root->cfg->setFrontBet(nnrs->iAnte);
                root->cfg->setSysProfit(nnrs->iProfit);
                root->cfg->setRaiseTime(nnrs->iRaiseTime);
                root->cfg->setTempFlag(0);
                
                __CATCH__
                PERFSTATS_EXIT();
            }
        }
    }
}
