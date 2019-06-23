#pragma once

#include <eigen3/Eigen/Dense>
#include <ceres/ceres.h>
#include "../utility/utility.h"

//�����е����г�Ա��������ceres::localParameterization���еĴ��麯��
class PoseLocalParameterization : public ceres::LocalParameterization
{
    virtual bool Plus(const double *x, const double *delta, double *x_plus_delta) const;
    virtual bool ComputeJacobian(const double *x, double *jacobian) const;
    //��Ϊλ��ֻ����ά������Ԫ��ȴ����λ����������,GlobalSize��ʾ������Ԫ����ʾ����ά�ȣ�localSize��ʾ����ʵ��λ�˾��е�ά��
    virtual int GlobalSize() const { return 7; };//The dimension of the ambient space in which the parameter block x lives.
    virtual int LocalSize() const { return 6; };//The size of the tangent space that ��x lives in.
};
