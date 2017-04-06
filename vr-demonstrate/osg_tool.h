#pragma once
#include <osg/Vec3>
#include <osg/Vec4>
#include <osg/nodevisitor>
#include <osg/MatrixTransform>
#include <osg/MatrixTransform>
#include <ostream>

namespace osg
{
	class Geode;
	class Shape;
	class Geometry;
	class Drawable;
}

enum GridType
{
	kXY,
	kXZ,
	kYZ,
};
std::ostream& operator << (std::ostream& out, const osg::Vec3& v);

osg::Geode* MakeGrid(GridType grid_type, 
						int num,
						double delta = 1.0, 
						const osg::Vec4& axis_color = osg::Vec4(0.9, 0.0, 0.0, 1.0), 
						const osg::Vec4& grid_color = osg::Vec4(0.1, 0.1, 0.1, 1.0)
						);

osg::Drawable* DrawPoint(const osg::Vec3& coord, const osg::Vec4& color, float size);

osg::Drawable* DrawLine(const osg::Vec3& first_vertex_coord, const osg::Vec3& second_vertex_coord, const osg::Vec4& color, float line_width = 1.0f);
//�ж��Ƿ��ǹ�����
osg::Shape* JudgeRegularShape(osg::Geometry* geom);
//ȥ�����ඥ��
void makeMesh(osg::Geometry* geom);

//�������н�rad
double intersectionAngle(const osg::Vec3& p0, const osg::Vec3& p1);



osg::PositionAttitudeTransform* CreatePosPAT(const osg::Vec3& pos);
osg::Geode* CreateLables(const osg::Vec3& pos, float size, const osg::Vec4& color, const std::string& label);
osg::Geode* CreateAxis();

//��ȡ�ڵ����������
class WorldCoordGetter : public osg::NodeVisitor
{
public:
	WorldCoordGetter() :
	  osg::NodeVisitor(NodeVisitor::TRAVERSE_PARENTS), done(false)
	  {
		  wcMatrix = new osg::Matrixd();
	  }
	  virtual void apply(osg::Node & node)
	  {
		  if(!done)
		  {
			  //������ڵ㣬��ʱ�ڵ�·��Ҳ�Ѽ�¼����
			  if(0 == node.getNumParents())
			  {
				  wcMatrix->set(osg::computeLocalToWorld(this->getNodePath()));
				  done = true;
			  }
			  //��������
			  traverse(node);
		  }
	  }
	  //���������������
	  osg::Matrixd* giveUpDaMat()
	  {
		  return wcMatrix;
	  }
	  //���㳡����ĳ���ڵ���������꣬����osg::Matrix��ʽ����������
	  //�������ڸ��������������ķ������󣬼���ȡ�þ���
	  static osg::Matrixd* getWorldCoords(osg::Node* node)
	  {
		  WorldCoordGetter* ncv = new WorldCoordGetter();
		  if(node && ncv)
		  {
			  //���÷�����
			  node->accept(*ncv);
			  return ncv->giveUpDaMat();
		  }
		  else
			  return NULL;
	  }
private:
	bool done;
	osg::Matrix* wcMatrix;
};
