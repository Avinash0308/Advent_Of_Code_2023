#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <set>

std::tuple<std::string, std::string> p05(const std::string &input)
{
    int64_t ans1 = 0;
    int64_t ans2 = 0;

    std::vector<int64_t> seeds;
    std::vector<std::vector<std::tuple<int64_t, int64_t, int64_t>>> maps;
    {
        bool have_seeds = false;
        int64_t num = 0;
        bool havenum = false;
        std::vector<int64_t> row;
        for (const auto c : input)
        {
            if (c >= '0' && c <= '9')
            {
                num *= 10;
                num += c - '0';
                havenum = true;
            }
            else
            {
                if (havenum)
                {
                    if (!have_seeds)
                    {
                        seeds.push_back(num);
                    }
                    else
                    {
                        row.push_back(num);
                    }
                }
                if (c == ':' && have_seeds)
                {
                    maps.emplace_back();
                }
                if (c == '\n')
                {
                    if (have_seeds)
                    {
                        if (row.size() == 3)
                        {
                            maps.back().emplace_back(row[0], row[1], row[2]);
                        }
                    }
                    row.clear();
                    have_seeds = true;
                }
                havenum = false;
                num = 0;
            }
        }
    }

    ans1 = std::numeric_limits<int64_t>::max();
    ans2 = std::numeric_limits<int64_t>::max();

    for (auto &m : maps)
    {
        std::sort(m.begin(), m.end(), [](const auto &m1, const auto &m2)
                  { return std::get<1>(m1) < std::get<1>(m2); });
    }

    decltype(maps) newmap;
    for (auto &m : maps)
    {
        int64_t last = 0;
        newmap.emplace_back();
        for (auto it : m)
        {
            int64_t d = std::get<0>(it), s = std::get<1>(it), l = std::get<2>(it);
            if (last < s)
            {
                newmap.back().emplace_back(last, last, s - last);
            }
            newmap.back().emplace_back(d, s, l);
            last = s + l;
        }
        newmap.back().emplace_back(last, last, std::numeric_limits<int64_t>::max() - last);
    }

    maps.swap(newmap);

    for (auto p : {1, 2})
    {
        for (decltype(seeds)::size_type i = 0; i < seeds.size(); i += p)
        {
            std::vector<std::tuple<int64_t, int64_t>> pairs;
            pairs.emplace_back(seeds[i], (p == 1 ? 1 : seeds[i + 1])); //??
            for (const auto &m : maps)
            {
                std::vector<std::tuple<int64_t, int64_t>> newpairs;
                for (auto it : pairs)
                {
                    int64_t seedstart = std::get<0>(it), seedlen = std::get<1>(it);
                    if (seedlen <= 0)
                        break;
                    for (auto itt : m)
                    {
                        int64_t dest = std::get<0>(itt), src = std::get<1>(itt), len = std::get<2>(itt);
                        auto overlap = [](int64_t min1, int64_t max1, int64_t min2, int64_t max2)
                        {
                            return std::max(int64_t(0), std::min(max1, max2) - std::max(min1, min2));
                        };
                        auto ol = overlap(seedstart, seedstart + seedlen, src, src + len);
                        if (ol)
                        {
                            int64_t newstart = 0;
                            if (seedstart > src)
                                newstart = dest + seedstart - src;
                            else
                                newstart = dest + src - seedstart;
                            newpairs.emplace_back(newstart, ol);
                        }
                        seedlen -= ol;
                        seedstart += ol;
                    }
                }
                pairs.swap(newpairs);
            }
            for (auto it : pairs)
            {
                int64_t seed = std::get<0>(it), l = std::get<1>(it);
                auto &ans = (p == 1 ? ans1 : ans2);
                if (seed < ans)
                    ans = seed;
            }
        }
    }

    return {std::to_string(ans1), std::to_string(ans2)};
}
int main()
{
    const std::string s = {"seeds: 3489262449 222250568 2315397239 327729713 1284963 12560465 1219676803 10003052 291763704 177898461 136674754 107182783 2917625223 260345082 1554280164 216251358 3900312676 5629667 494259693 397354410\nseed-to-soil map:\n0 262295201 34634737\n910271444 3030771176 70771974\n1897698334 3827766493 333942393\n2835207376 3155028665 271883030\n3622783763 1954868220 45665001\n413310490 329609945 44648194\n4240712808 2423731337 1828518\n1316121579 1728110187 80499681\n2250966941 2228145658 118984728\n2516210021 2142630093 85515565\n1864536239 3101543150 33162095\n34634737 296929938 32680007\n329609945 374258139 83700545\n3329626425 2142012590 617503\n2601725586 1531355997 196754190\n3709721314 2000533221 47790630\n3583007889 3526843691 39775874\n4060705901 1494770107 36585890\n3330243928 2694462608 4855344\n3668448764 1219440337 41272550\n3872593248 2347130386 76600951\n67314744 0 262295201\n1396621260 4161708886 65683132\n3549978104 3678131267 33029785\n3949194199 3566619565 111511702\n1482627812 2425559855 249576539\n3757511944 4236759076 58208220\n875524978 2831649840 34746466\n4242541326 4227392018 9367058\n3107090406 1260712887 107855696\n4097291791 2887350159 143421017\n4251908384 3483784779 43058912\n981043418 749361185 218472720\n749361185 1368568583 126163793\n3335099272 1004561505 214878832\n2798479776 967833905 36727600\n3214946102 1494732376 37731\n3308672572 2866396306 20953853\n2369951669 1808609868 146258352\n1199516138 3711161052 116605441\n1732204351 2699317952 132331888\n3214983833 2048323851 93688739\n1462304392 3134705245 20323420\n3815720164 3426911695 56873084\n2231640727 2675136394 19326214\n\nsoil-to-fertilizer map:\n1819561283 2841304997 237877444\n4006405251 2649445491 24162567\n212683490 0 763350919\n1389184545 2619909475 29536016\n1221487606 2673608058 167696939\n3182207211 2119363521 157025339\n2057563716 1221487606 435495557\n976034409 1008691842 1136514\n2493059273 3079182441 511127728\n3339232550 1835003373 284360148\n3623592698 3912154743 382812553\n3004187001 1656983163 178020210\n977170923 987370593 21321249\n58558242 763350919 154125248\n998492172 976034409 11336184\n4030567818 2276513849 264399478\n0 917476167 58558242\n2057438727 2276388860 124989\n1418720561 2540913327 78996148\n1497716709 3590310169 321844574\n\nfertilizer-to-water map:\n252374398 77740491 188270615\n1590959511 1400999811 20005707\n1019974286 266011106 27332620\n1085156732 1443065767 85008355\n4080487124 1647556561 104750479\n3094480335 3707305578 360771904\n4185237603 4248557616 46409680\n3828418017 2355725650 21816275\n1626753532 4068077482 180480134\n1568899262 1421005518 22060249\n1807233666 3705123159 2182419\n1809416085 1626753532 20803029\n3998962584 2274201110 81524540\n440645013 1177871937 219366450\n1520096568 1397238387 3761424\n1523857992 1528074122 45041270\n174633907 0 77740491\n1170165087 293343726 349931481\n3850234292 2125472818 148728292\n2953301907 3563944731 141178428\n660011463 817909114 359962823\n4231647283 3500624718 63320013\n0 643275207 174633907\n1830219114 2377541925 1123082793\n1047306906 1573115392 37849826\n3455252239 1752307040 373165778\n\nwater-to-light map:\n3713102322 3195199062 109343869\n940512817 264084495 97517772\n2334334472 1383468484 100556669\n465645319 1958405710 14984685\n3303747025 4294646763 320533\n2616072044 2768562044 426637018\n1599136731 361602267 86797445\n480630004 53689017 41315440\n244424239 1902592526 55813184\n521945444 1484025153 418567373\n3208097188 2507524081 95649837\n3933959318 3799485319 28619103\n3822446191 4288382866 6263897\n53689017 2385517268 49373873\n1109731683 1973390395 151930940\n3865952749 4063808346 68006569\n2013172224 496719573 124139241\n2223150247 620858814 76066751\n196104378 448399712 48319861\n2299216998 2350399794 35117474\n3710229881 3304542931 2872441\n2137311465 1005624092 85838782\n1516868628 923355989 82268103\n103062890 830314501 93041488\n2459504093 4131814915 156567951\n1457198065 2290729231 59670563\n3042709062 2603173918 165388126\n1261662623 1357013080 26455404\n419510562 2244594474 46134757\n3304067558 2459504093 48019988\n3828710088 3665557707 37242661\n3352087546 3307415372 358142335\n1819323112 1091462874 193849112\n3962578421 3702800368 96684951\n1038030589 1285311986 71701094\n4059263372 3828104422 235703924\n300237423 2125321335 119273139\n1288118027 95004457 169080038\n1685934176 696925565 133388936\n\nlight-to-temperature map:\n933106075 308278269 212548971\n3133283890 2353712179 197530061\n2425741949 3555777393 99769003\n932513834 722519986 592241\n2970285248 1818047303 41216585\n2702880712 2943782997 36451052\n1420185365 1065216599 145812917\n1172773874 1429440708 136557574\n3565704029 2551242240 35862216\n0 723112227 1274616\n354926437 520827240 17525539\n3896280620 3932683708 23800931\n891510185 724386843 1792027\n1145655046 1211029516 27118828\n1587093819 3655546396 28108512\n372451976 682239540 40280446\n95189373 726178870 259737064\n3672435146 2980234049 58823724\n2559751700 2800653985 143129012\n3920081551 3363893446 191883947\n1274616 538352779 2436403\n1615202331 3685523873 66027002\n2231672737 2159642967 194069212\n3601566245 4075105446 70868901\n2028619121 3160839830 203053616\n2739331764 1587093819 230953484\n3811900561 3956484639 84380059\n893302212 540789182 39211622\n412732422 1361179950 68260758\n4111965498 3751550875 181132833\n2525510952 4040864698 34240748\n789271449 580000804 102238736\n480993180 0 308278269\n1309331448 1329626698 31553252\n3731258870 2775912020 24741965\n3756000835 1859263888 55899726\n1681229333 2587104456 188807564\n3330813951 4145974347 148992949\n1340884700 985915934 79300665\n3711019 1238148344 91478354\n3011501833 3039057773 121782057\n1870036897 1915163614 158582224\n4293098331 3683654908 1868965\n3479806900 2073745838 85897129\n\ntemperature-to-humidity map:\n3171909692 2207313208 125557542\n3910448973 3971234589 267130124\n2271924206 3732981386 64142303\n1112427243 457977609 299980445\n533481406 191448702 131397640\n2336066509 3020855282 21496528\n26829166 1125772826 208642920\n3547574211 3901910422 69324167\n235472086 0 100639414\n3346614381 3623211928 109769458\n3472548902 3256633041 51082372\n2371444946 4238364713 56602583\n0 100639414 26829166\n3658517236 3410551372 212660556\n3102881240 3307715413 69028452\n2428047529 2368475416 534316082\n336111500 322846342 55397842\n4250847842 2163193754 44119454\n3871177792 3042351810 39271181\n3616898378 3105565928 41618858\n2962363611 3376743865 33807507\n1412407688 1334415746 499813714\n3523631274 3081622991 23942937\n1032693818 378244184 79733425\n2161270365 2902791498 80399705\n3456383839 3147184786 16165063\n2998094507 3797123689 104786733\n664879046 757958054 367814772\n2996171118 2161270365 1923389\n391509342 1834229460 77991942\n2357563037 3212496996 13881909\n469501284 127468580 63980122\n3297467234 3163349849 49147147\n4177579097 2332870750 35604666\n2241670070 3226378905 30254136\n4213183763 2983191203 37664079\n\nhumidity-to-location map:\n4240687605 3509581493 54279691\n3450687144 1997031321 128004903\n3703408300 2316680098 55200017\n2797906577 2125036224 66927621\n3758608317 1680202206 316829115\n2970872896 1200387958 479814248\n2864834198 1094349260 106038698\n3578692047 2191963845 124716253\n4075437432 3563861184 165250173\n2232050638 3729111357 565855939\n1094349260 2371880115 1137701378\n"}; 
    std::tuple<std::string, std::string>ans = p05(s);
    auto it = ans;
    std::string seed = std::get<0>(it), l = std::get<1>(it);
    std::cout<<seed<<std::endl;
    std::cout<<l<<std::endl;
}