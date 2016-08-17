#include "quickVtkPiecewiseFunction.hpp"

namespace quick {

    namespace Vtk {

        Qml::Register::UncreatableClass<PiecewiseFunction> PiecewiseFunction::Register;

        PiecewiseFunction::PiecewiseFunction(cb_t&& callback) : m_callback(callback) {
        }

        auto PiecewiseFunction::getX(int i) -> double {
            return this->m_xValues.at(i);
        }

        auto PiecewiseFunction::getY(int i) -> double {
            return this->m_yValues.at(i);
        }

        auto PiecewiseFunction::notify() -> void {
            this->m_callback.operator()();
        }

        auto PiecewiseFunction::setXValues(QList<double> xValues) -> void {
            this->m_xValues = xValues;
            emit this->xValuesChanged();
            this->notify();
        }

        auto PiecewiseFunction::getXValues() -> QList<double> {
            return this->m_xValues;
        }

        auto PiecewiseFunction::setYValues(QList<double> yValues) -> void {
            this->m_yValues = yValues;
            emit this->yValuesChanged();
            this->notify();
        }

        auto PiecewiseFunction::getYValues() -> QList<double> {
            return this->m_yValues;
        }

        auto PiecewiseFunction::getLength() -> int {
            return this->m_yValues.length();
        }
    }
}
