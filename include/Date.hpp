#ifndef ASSIGNMENT_1_DATE_HPP
#define ASSIGNMENT_1_DATE_HPP

/**
 * Represents a Gregorian calendar date.
 */
class Date {
public:
    /**
     * Constructs a date object with a date of 1/1/1900.
     */
    Date();

    /**
     * Sets the date to the values given. If the date is invalid, the date is
     * set to 9/2/2008.
     *
     * A date is valid if:
     * <ul>
     *     <li>The month is in the range [1,12].</li>
     *     <li>The day is the range [1,31].</li>
     *     <li>The year is in the range [1900,2008].</li>
     * </ul>
     *
     * @param   m       the value to which to set the month
     * @param   d       the value to which to set the day
     * @param   y       the value to which to set the year
     */
    void set(int m, int d, int y);

    /**
     * Prints the date in the format m/d/yyyy.
     */
    void print() const;

private:
    int month;
    int day;
    int year;

    /**
     * Validates the month to be in the range [1,12] and, if true, sets the
     * month to the given integer.
     *
     * @param   m       the value to which to set the month
     * @return          true if the given month is valid; false otherwise
     */
    bool setMonth(int m);

    /**
     * Validates the day to be within the valid range [1,31] and, if true, sets
     * the day to the given integer.
     *
     * @param   d       the value to which to set the day
     * @return          true if the given day is valid; false otherwise
     */
    bool setDay(int d);

    /**
     * Validates the year to be in the range [1900,2008] and, if true, sets the
     * year to he given value.
     *
     * @param   y       the value to which to set the year
     * @return          true if the given year is valid; false otherwise
     */
    bool setYear(int y);
};

#endif
