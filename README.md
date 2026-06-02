# Hold'em AI Source / 德州AI源码/德州源码/德州撲克AI源码合集 / 德州撲克AI源码合集

[![GitHub stars](https://img.shields.io/github/stars/deepseek7878/holdem-ai-source?style=for-the-badge)](https://github.com/deepseek7878/holdem-ai-source)
[![GitHub forks](https://img.shields.io/github/forks/deepseek7878/holdem-ai-source?style=for-the-badge)](https://github.com/deepseek7878/holdem-ai-source)
[![Languages](https://img.shields.io/github/languages/top/deepseek7878/holdem-ai-source?style=for-the-badge)](https://github.com/deepseek7878/holdem-ai-source)
[![License](https://img.shields.io/github/license/deepseek7878/holdem-ai-source?style=for-the-badge)](https://github.com/deepseek7878/holdem-ai-source/blob/main/LICENSE)

**Texas Hold'em AI source code collection**  
CFR, Monte Carlo, rule-based, neural network bots for research, learning, and development / CFR、蒙特卡洛、规则AI、神经网络Bot，研究学习开发专用 / CFR、蒙特卡洛、規則AI、神經網絡Bot，研究學習開發專用.

## 🎯 AI算法一览 / AI Algorithms / AI演算法一覽

| 算法 | 语言 | 难度 | 特点 | 源码 |
|------|------|------|------|------|
| **规则Bot** | Python | 新手 | 简单易懂 | [查看](bots/rulebot/) |
| **Monte Carlo** | JavaScript | 中级 | 模拟搜索 | [查看](bots/montecarlo/) |
| **CFR** | Python | 高级 | 纳什均衡 | [查看](bots/cfr/) |
| **Minimax** | C++ | 高级 | 精确搜索 | [查看](bots/minimax/) |
| **神经网络** | PyTorch | 专家 | DQN训练 | [查看](bots/neural/) |

## 🚀 快速运行 / Quick Start / 快速運行

```bash
# 1. 下载源码
git clone https://github.com/deepseek7878/holdem-ai-source.git
cd holdem-ai-source

# 2. 运行规则Bot (最简单)
cd bots/rulebot
python main.py

# 3. 运行CFR (推荐)
cd bots/cfr
pip install -r requirements.txt
python train.py --iterations 10000
python play.py

# 4. 对战测试
python benchmark.py --bots rulebot cfr montecarlo
```

## 📊 对战排行 / Bot Rankings / Bot排名
CFR Bot: 胜率82% (10k手)

Monte Carlo: 胜率67%

Minimax: 胜率59%

Rule Bot: 胜率48%

Random: 胜率12%



## 🧠 算法详解 / Algorithm Details / 演算法詳解

### **1. 规则Bot (Rule-based)**
if nuts_strength > opponent_range:
raise 3x pot
elif position == button:
call
else:
fold

text
**适用：** 学习基础决策逻辑

### **2. Monte Carlo Simulation**
for i in range(10000):
simulate_remaining_board()
evaluate_equity()
return average_equity


**适用：** 中期决策胜率计算

### **3. CFR (Counterfactual Regret Minimization)**
regret_sum += counterfactual_regret
strategy = regret_matching(regret_sum)


**适用：** 接近纳什均衡

### **4. Minimax with Alpha-Beta**
max_value = max(minimax(child, depth-1, False))
min_value = min(minimax(child, depth-1, True))


**适用：** 小牌桌精确搜索

## 🏗️ 项目结构 / Structure / 結構
holdem-ai-source/
├── bots/
│ ├── rulebot/ # 规则AI
│ ├── montecarlo/ # 蒙特卡洛
│ ├── cfr/ # CFR核心
│ └── neural/ # 神经网络
├── common/
│ ├── engine.py # 扑克引擎
│ └── evaluator.py # 牌型判断
├── benchmarks/ # 对战测试
└── notebooks/ # Jupyter示例

text

## 🎮 快速测试 / Quick Test / 快速測試

```bash
# 安装测试环境
pip install -r test-requirements.txt

# 基准测试所有Bot
python benchmark.py

# 自定义对战
python battle.py --bot1 cfr --bot2 montecarlo --hands 10000
```

## 📈 性能对比 / Performance / 效能對比

| Bot | 决策时间 | 胜率 | 内存 |
|-----|----------|------|------|
| Rule | 0.1ms | 48% | 20MB |
| Monte Carlo | 25ms | 67% | 45MB |
| CFR | 8ms | 82% | 120MB |
| Minimax | 150ms | 59% | 80MB |

## 🔧 开发者指南 / Developer Guide / 開發者指南

### **集成到你的项目**
```python
from bots.cfr import CFRBot
from common.engine import TexasHoldem

game = TexasHoldem(6)
bot = CFRBot()

while game.is_running():
    action = bot.get_action(game.state)
    game.player_action(action)
```

### **自定义训练**
```python
# config.json
{
  "iterations": 100000,
  "simulations": 5000,
  "exploration": 1.4
}
```

## 🛠️ 环境配置 / Environment / 環境配置
Python 3.8+ (推荐)
PyTorch 1.12+ (神经网络)
NumPy / SciPy
Jupyter (notebook演示)
Docker (统一环境)



## 📦 源码包下载 / Source Packages / 源码包
规则Bot包 - 1.2MB
CFR完整包 - 8.5MB
全套源码 - 25MB



## 🎯 学习路径 / Learning Path / 學習路徑
规则Bot → 理解基础决策

Monte Carlo → 胜率计算

CFR → 博弈论深度

神经网络 → 深度学习

集成实战 → 完整项目



## 🔬 研究参考 / Research Reference / 研究參考
✅ Libratus论文复现
✅ Pluribus架构参考
✅ PioSOLVER策略验证
✅ 胜率基准测试



## 🤝 贡献指南 / Contributing / 貢獻指南
✅ 新AI算法
✅ 性能优化
✅ 更多语言实现
✅ 测试用例
✅ 文档完善
✅ Docker封装
## 📱 💰 获取源码 | Contact


📱 Telegram：@fox_lovemyself


📧 Email：lihongbo9414@gmail.com

## 产品截图
<img width="235" height="324" alt="微信图片_20250713160546" src="https://github.com/user-attachments/assets/5e929684-9ccc-4149-8920-2ed421f9d528" />

<img width="1050" height="706" alt="微信图片_20241030103520" src="https://github.com/user-attachments/assets/db706fbe-1679-4215-9330-6219efef53d2" />
<img width="952" height="479" alt="微信图片_20241203165105" src="https://github.com/user-attachments/assets/6f071b5e-97fc-4ca9-a8e1-3d4620c9c64c" />



## 📄 License
MIT License - AI研究商用友好
Copyright (c) 2026 deepseek7878

text

---

**⭐ Star收藏扑克AI源码库！ / Star poker AI source collection! / Star收藏撲克AI源码庫！**


