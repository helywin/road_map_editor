//
// Created by jiang on 2021/6/9.
//

#ifndef MAP_EDITOR_UTILS_HPP
#define MAP_EDITOR_UTILS_HPP

#include <stddef.h>
#include <type_traits>

class QObject;
class QWidget;

template<typename W, typename WP>
inline void initWidget(W *&w, WP *wp)
{
    w = new W(wp);
}

template<typename O>
inline void initObject(O *&o, QObject *op)
{
    o = new O(op);
}

template<typename WPP, size_t N, typename WP>
inline void initWidgets(WPP (&w)[N], WP *wp)
{
    using W = typename std::remove_pointer<WPP>::type;
    for (int i = 0; i < N; ++i) {
        w[i] = new W(wp);
    }
}

template<typename WPP, size_t N, size_t K, typename WP>
inline void initWidgets(WPP (&w)[N][K], WP *wp)
{
    using W = typename std::remove_pointer<WPP>::type;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            w[i][j] = new W(wp);
        }
    }
}

void drawPrimitive(QWidget *w);


#endif //MAP_EDITOR_UTILS_HPP
