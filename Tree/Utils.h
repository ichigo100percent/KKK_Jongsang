#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct Point
{
    float x;
    float y;

    Point()
    {

    }
    Point(float _x, float _y)
        :x(_x), y(_y)
    {

    }

    Point operator + (Point& p)
    {
        return Point(x + p.x, y + p.y);
    }
    Point operator - (Point& p)
    {
        return Point(x - p.x, y - p.y);
    }
    Point operator * (Point& p)
    {
        return Point(x * p.x, y * p.y);
    }
    Point operator / (Point& p)
    {
        return Point(x / p.x, y / p.y);
    }
};

struct Rect
{
    float m_x;
    float m_y;
    float m_width;
    float m_height;

    Point m_Point[4];
    Point m_Center;
    Point m_Half;
    Point m_Min;
    Point m_Max;
    Point v;
    Point s;

    void Set(float _x, float _y, float _w, float _h)
    {
        v = { _x, _y };
        s = { _w, _h };

        m_x = _x;
        m_y = _y;
        m_width = _w;
        m_height = _h;

        m_Half = { m_width * 0.5f, m_height * 0.5f };
        m_Point[0] = { m_x, m_y };
        m_Point[1] = { m_x + m_width, m_y };
        m_Point[2] = { m_x + m_width, m_y + m_height };
        m_Point[3] = { m_x, m_y + m_height };

    }

    Rect()
    {

    }
    Rect(float _x, float _y, float _w, float _h)
    {
        Set(_x, _y, _w, _h);
    }

};
