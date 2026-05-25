#include "common/macros.h"
#include "gameroot.h"
#include "context/context.h"
#include "Comm/ITableGame.h"
#include "utils/tarslog.h"
#include "message/sendclientmessage.h"
#include "logic/gamelogic/core/checkbegin.h"
#include "process/process.h"
#include "CommonCode.pb.h"
#include "dz.pb.h"

namespace game
{
    namespace logic
    {
        namespace roomlogic
        {
            long GetUserInfo(void const *p, GameRoot *root)
            {
                __TRY__

                using namespace RoomSo;
                using namespace context;
                using namespace message;
                using namespace gamelogic;
                using namespace process;

                //
                TGAME_GetUserInfo const *nnrs = static_cast<TGAME_GetUserInfo const *>(p);
                //DLOG_TRACE("roomkey:" << root->cfg->getRoomKey()<<", "<<"TGAME_UserInfo_E" << ", uid: " << nnrs->lPlayerID);

                //玩家对象
                User *user = root->con->getUserByUid(nnrs->lPlayerID);
                if (user == NULL)
                {
                    RLOG_DEBUG << "user not exist, uid: " << nnrs->lPlayerID << endl;

                    return 0;
                }

                if(nnrs->iType == 1)
                {
                    if(user->getPauseStartTime() > 0 && user->isPause())
                    {
                        return user->getPauseEndTime() <= TNOW ? 1 : 0;
                    }
                    long holdSeatTime = root->con->getHoldSeatTimeByUid(user->getUid());
                    if( holdSeatTime > 0)
                    {
                        if(holdSeatTime <= TNOW)
                        {
                            XGameDZProto::NN_msg2sGameNotice nncm;
                            nncm.set_inoticetype(XGameRetCode::GAME_HOLD_SEAT_TIMEOUT);
                            sendClientMessage<XGameDZProto::NN_msg2sGameNotice>(user->getUid(), XGameDZProto::NN_msg2csGameNotice_E, nncm, root);
                            return 1;
                        }
                        return 0;
                    }
                }
                else
                {
                    return user->getDZWealth();
                }

                return 0;

                __CATCH__
                return 0;
            }
        }
    }
}
