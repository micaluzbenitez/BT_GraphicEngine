#include "Entity.h"
//http://www.c-jump.com/bcc/common/Talk3/Math/GLM/GLM.html#W01_0030_matrix_transformation
const float deg2rad = (glm::pi<float>() * 2.0f) / 360.0f;

Entity::Entity()
{
    model = glm::mat4(1.0f);

    translateMatrix = glm::mat4(1.0f);
    rotationMatrix = glm::mat4(1.0f);
    scaleMatrix = glm::mat4(1.0f);
    
    translateVector = glm::vec3(1.0f);
    rotationVector = glm::vec3(1.0f);
    scaleVector = glm::vec3(1.0f);

    VBO = 0;
    VAO = 0;
    EBO = 0;
	
    renderer = nullptr;
}

Entity::~Entity()
{
    if (renderer != nullptr) {
        renderer = nullptr;
        delete renderer;
    }
}

glm::mat4 Entity::GetModelMatrix()
{
    model = glm::mat4(1.0f);
    model *= scaleMatrix * rotationMatrix * translateMatrix;
    return model;
}

void Entity::SetPosition(float x, float y, float z)
{
    translateVector = glm::vec3(x, y, z); //Va a modificar la mat
    translateMatrix[3].x = x;
    translateMatrix[3].y = y;
    translateMatrix[3].z = z;
}

void Entity::SetRotation(float x, float y, float z)
{
    rotationVector = glm::vec3(x, y, z); //Va a modificar la mat
}

void Entity::SetScale(float x, float y, float z)
{
    scaleVector = glm::vec3(x, y, z); //Va a modificar la mat
    scaleMatrix[0].x = x;
    scaleMatrix[1].y = y;
    scaleMatrix[2].z = z;
}

glm::vec3 Entity::GetPosition()
{
    return translateVector;
}

glm::vec3 Entity::GetRotation()
{
    return rotationVector;
}

glm::vec3 Entity::GetScale()
{
    return scaleVector;
}


void Entity::Translate(float x, float y, float z)
{
    translateMatrix = glm::translate(translateMatrix, glm::vec3(x, y, z));
    translateVector = glm::vec3(translateMatrix[3].x, translateMatrix[3].y, translateMatrix[3].z);
}

void Entity::Rotate(float x, float y, float z)
{
    rotationMatrix = glm::rotate(rotationMatrix, x, glm::vec3(1, 0, 0));
    rotationMatrix = glm::rotate(rotationMatrix, y, glm::vec3(0, 1, 0));
    rotationMatrix = glm::rotate(rotationMatrix, z, glm::vec3(0, 0, 1));
    //rotationVector

}

void Entity::Scale(float x, float y, float z)
{
    scaleMatrix = glm::scale(scaleMatrix, glm::vec3(x, y, z));
    scaleVector = glm::vec3(scaleMatrix[0].x, scaleMatrix[1].y, scaleMatrix[2].z);
}

/*
glm::quat Entity::EulerToQuat(glm::vec3 euler)
{
    euler *= deg2rad;

    float cy = cos(euler.z * 0.5f);
    float sy = sin(euler.z * 0.5f);
    float cp = cos(euler.x * 0.5f);
    float sp = sin(euler.x * 0.5f);
    float cr = cos(euler.y * 0.5f);
    float sr = sin(euler.y * 0.5f);

    glm::quat q;
    q.w = cr * cp * cy + sr * sp * sy;
    q.x = cr * sp * cy + sr * cp * sy;
    q.y = sr * cp * cy - cr * sp * sy;
    q.z = cr * cp * sy - sr * sp * cy;
    return q;
}

glm::vec3 Entity::QuatToVec(glm::quat quat, glm::vec3 vec)
{
    float x2 = quat.x * 2.f;
    float y2 = quat.y * 2.f;
    float z2 = quat.z * 2.f;
    float xx2 = quat.x * x2;
    float yy2 = quat.y * y2;
    float zz2 = quat.z * z2;
    float xy2 = quat.x * y2;
    float xz2 = quat.x * z2;
    float yz2 = quat.y * z2;
    float wx2 = quat.w * x2;
    float wy2 = quat.w * y2;
    float wz2 = quat.w * z2;

    glm::vec3 res;
    res.x = (1.f - (yy2 + zz2)) * vec.x + (xy2 - wz2) * vec.y + (xz2 + wy2) * vec.z;
    res.y = (xy2 + wz2) * vec.x + (1.f - (xx2 + zz2)) * vec.y + (yz2 - wx2) * vec.z;
    res.z = (xz2 - wy2) * vec.x + (yz2 + wx2) * vec.y + (1.f - (xx2 + yy2)) * vec.z;
    return res;
}

glm::quat Entity::QuaternionLookRotation(glm::vec3 forward, glm::vec3 upwards)
{

        forward = glm::normalize(forward);                                 /// 0, 0, 1
        glm::vec3 right = glm::normalize(glm::cross(upwards, forward));   /// 1, 0, 0
        upwards = glm::cross(forward, right);                              /// 0, 1, 0 

        float m00 = right.x;
        float m01 = right.y;
        float m02 = right.z;
        float m10 = upwards.x;
        float m11 = upwards.y;
        float m12 = upwards.z;
        float m20 = forward.x;
        float m21 = forward.y;
        float m22 = forward.z;

        float diagonal = m00 + m11 + m22;
        float qw = 0;
        float qx = 0;
        float qy = 0;
        float qz = 0;

        if (diagonal > 0)
        {
            float wComponent = glm::sqrt(diagonal + 1.0f) * 2;
            qw = 0.25f * wComponent;
            qx = (m21 - m12) / wComponent;
            qy = (m02 - m20) / wComponent;
            qz = (m10 - m01) / wComponent;
        }
        else if ((m00 > m11) && (m00 > m22))
        {
            float wComponent = glm::sqrt(1.0f + m00 - m11 - m22) * 2;
            qw = (m21 - m12) / wComponent;
            qx = 0.25f * wComponent;
            qy = (m01 + m10) / wComponent;
            qz = (m02 + m20) / wComponent;
        }
        else if (m11 > m22)
        {
            float wComponent = glm::sqrt(1.0f + m11 - m00 - m22) * 2;
            qw = (m02 - m20) / wComponent;
            qx = (m01 + m10) / wComponent;
            qy = 0.25f * wComponent;
            qz = (m12 + m21) / wComponent;
        }
        else
        {
            float wComponent = glm::sqrt(1.0f + m22 - m00 - m11) * 2;
            qw = (m10 - m01) / wComponent;
            qx = (m02 + m20) / wComponent;
            qy = (m12 + m21) / wComponent;
            qz = 0.25f * wComponent;
        }

        return glm::quat(qx, qy, qz, qw);
    
}
*/