#include "math_utils.hpp"

double math_utils::calc_distance(const Point &a, const Point &b)
{
    return std::hypot((b.x - a.x), (b.y - b.x));
}

math_utils::Point math_utils::calc_centroid(const std::vector<Point> &points)
{
    if (points.empty())
        return {0.0, 0.0};

    double sum_x = std::accumulate(points.begin(), points.end(), 0.0,
                                   [](double acc, const Point &elem)
                                   { return acc + elem.x; });
    double sum_y = std::accumulate(points.begin(), points.end(), 0.0,
                                   [](double acc, const Point &elem)
                                   { return acc + elem.y; });

    return {sum_x / static_cast<double>(points.size()),
            sum_y / static_cast<double>(points.size())};
}

std::vector<math_utils::Point> math_utils::load_numbers(const std::filesystem::path &path)
{
    std::vector<Point> points;

    std::ifstream file(path);
    if (!file)
        throw std::ios_base::failure("File not found.");

    double x, y;
    while (file >> x)
    {
        if (!(file >> y))
        {
            if (file.eof())
                throw std::runtime_error("The file contains odd amount of points");
            else
                throw std::runtime_error("Error reading double");
        }
        points.push_back({x, y});
    }

    if (points.empty())
        throw std::logic_error("No points were read from the file");

    return points;
}

std::ostream &math_utils::operator<<(std::ostream &os, const Point &point)
{

    os << point.x << '\t' << point.y;
    return os;
}
