#include "common/macros.h"
#include "gameroot.h"
#include "context/context.h"
#include "Comm/ITableGame.h"
#include "utils/tarslog.h"
#include "process/process.h"
#include "config/gameconfig.h"

namespace game
{
    namespace logic
    {
        namespace roomlogic
        {
            void ConstConfig(void const *p, GameRoot *root)
            {
                PERFSTATS_ENTRY();
                __TRY__

                using namespace RoomSo;
                using namespace context;
                using namespace process;
                using namespace config;

                RoomSo::TGAME_ConstConfig const *nnrs = static_cast<RoomSo::TGAME_ConstConfig const *>(p);
                DLOG_TRACE("roomkey:" << root->cfg->getRoomKey()<<", "<<"TGAME_ConstConfig_E" << ", data: " << printTars(*nnrs));

                //设置常量配置
                root->con->setConstConfig(*nnrs);

                __CATCH__
                PERFSTATS_EXIT();
            }
        }
    }
}
