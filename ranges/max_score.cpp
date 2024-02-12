#include <string>
#include <vector>
#include <ranges>
#include <algorithm>

struct Student
{
    int year_{};
    int score_{};
    std::string name_{};
};

auto max_value(auto &&range)
{
    auto max_it = std::ranges::max_element(range);
    return max_it == range.end() ? 0 : *max_it;
}

auto get_max_score_pipe(const std::vector<Student> &students, int year)
{
    // returns the max score of a student within a particular year
    // first filter the vector by year into a view
    auto by_year = [=](const Student &student)
    { return student.year_ == year; };
    // pipe students into a filtered view, then transformed to its projection
    // on the score
    // note that the transformation functions don't need to have the piped-through
    // view object as the argument, only the transformation callable itself
    auto view_by_year = students | std::views::filter(by_year) | std::views::transform(&Student::score_);
    return max_value(view_by_year);
}

auto get_max_score_direct_view(const std::vector<Student> &students, int year)
{
    auto by_year = [=](const Student &student)
    { return student.year_ == year; };
    // instead of using | to pipe range into a view, can construct view directly
    // the below uses initialiser lists and template type deduction!
    auto v1 = std::ranges::ref_view{students}; // wrap container in a view
    auto v2 = std::ranges::filter_view{v1, by_year}; // filter by year
    auto v3 = std::ranges::transform_view{v2, &Student::score_};
    return max_value(v3);
}