#include "../inc/my_matrix.hpp"

int create_matrix(my_matrix &m, const int &rows, const int &columns)
{
	m.data = (double **) calloc(rows, sizeof(double *));
	if (!m.data)
		return ERR_MEMORY;
	m.rows = 0;
	for (; m.rows < rows; m.rows++)
	{
		m.data[m.rows] = (double *) calloc(columns, sizeof(double));
		if (m.data[m.rows])
		{
			delete_matrix(m);
			return ERR_MEMORY;
		}
	}
	return OK;
}

void delete_matrix(my_matrix &m)
{
	for (int i = 0; i < m.rows; i++)
	{
		free(m.data[i]);
	}
	free(m.data);
	m.data = NULL;
}

void matrix_copy(my_matrix &m1, const my_matrix &m2)
{
	delete_matrix(m1);
	m1.data = m2.data;
	m1.rows = m2.rows;
	m1.columns = m2.columns;
}

int make_single_matrix(my_matrix &m)
{
	if (m.rows < 1 && m.columns < 1)
		return ERR_BAD_MATRIX;
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.columns; j++)
		{
			if (i == j)
				m.data[i][j] = 1;
			else
				m.data[i][j] = 0;
		}
	}
	return OK;
}

void grad_to_radian(double &radians, const double &degrees)
{
	radians = degrees*M_PI/180;
}

int make_rotate_matrix_x(my_matrix &m, const double &x)
{
	int rc = create_matrix(m, 4, 4);
	if (rc != OK)
		return rc;
	rc = make_single_matrix(m);
	if (rc != OK)
	{
		delete_matrix(m);
		return rc;
	}
	double radian_x;
	grad_to_radian(radian_x, x);

	m.data[1][1] = cos(x);
	m.data[1][2] = sin(x);
	m.data[2][1] = -sin(x);
	m.data[2][2] = cos(x);
	return OK;
}
int make_rotate_matrix_y(my_matrix &m, const double &y)
{
	int rc = create_matrix(m, 4, 4);
	if (rc != OK)
		return rc;
	rc = make_single_matrix(m);
	if (rc != OK)
	{
		delete_matrix(m);
		return rc;
	}
	double radian_y;
	grad_to_radian(radian_y, y);

	m.data[0][0] = cos(y);
	m.data[2][0] = sin(y);
	m.data[0][2] = -sin(y);
	m.data[2][2] = cos(y);
	return OK;
}
int make_rotate_matrix_z(my_matrix &m, const double &z)
{
	int rc = create_matrix(m, 4, 4);
	if (rc != OK)
		return rc;
	rc = make_single_matrix(m);
	if (rc != OK)
	{
		delete_matrix(m);
		return rc;
	}
	double radian_z;
	grad_to_radian(radian_z, z);

	m.data[0][0] = cos(z);
	m.data[0][1] = sin(z);
	m.data[1][0] = -sin(z);
	m.data[1][1] = cos(z);
	return OK;
}
int make_rotate_matrix(const command_parametres &settings, my_matrix &m)
{
	my_matrix m_x, m_y, m_xy, m_z, m_xyz;
	int rc;

	rc = make_rotate_matrix_x(m_x, settings.x);
	if (rc != OK)
		return rc;
	rc = make_rotate_matrix_y(m_y, settings.y);
	if (rc != OK)
	{
		delete_matrix(m_x); 
		return rc;
	}
	rc = make_rotate_matrix_z(m_z, settings.z);
	if (rc != OK)
	{
		delete_matrix(m_x);
		delete_matrix(m_z); 
		return rc;
	}
	rc = multiplicate_matrixes(m_xy, m_x, m_y);
	delete_matrix(m_x); 
	delete_matrix(m_y); 
	if (rc != OK)
		return rc;
	rc = multiplicate_matrixes(m_xyz, m_xy, m_z);
	delete_matrix(m_xy); 
	delete_matrix(m_z); 
	if (rc != OK)
		return rc;
	matrix_copy(m, m_xyz);
	return OK;
}

int make_transform_matrixes(my_matrix &m, const command_parametres &settings)
{
	create_matrix(m, 4, 4);
	make_single_matrix(m);
	switch(settings.operation)
	{
		case TRANSFER:
			m.data[3][0] = settings.x;
			m.data[3][1] = settings.y;
			m.data[3][2] = settings.z;
			break;
		case ROTATE:
			make_rotate_matrix(settings, m);
			break;
		case SCALE:
			m.data[0][0] = settings.x;
			m.data[1][1] = settings.y;
			m.data[2][2] = settings.z;
			break;
		default:
			return ERR_UNKNOWEN_COMMAND;
	}
    return OK;
}

int make_coordinates_from_matrixes(my_point &coordinates, const my_matrix &m)
{
	coordinates.x = m.data[0][0];
	coordinates.y = m.data[1][0];
	coordinates.z = m.data[2][0];
    return OK;
}
int make_coordinates_matrixes(my_matrix &m, const my_point &coordinates)
{
	create_matrix(m, 1, 4);
	m.data[0][0] = coordinates.x;
	m.data[0][1] = coordinates.y;
	m.data[0][2] = coordinates.z;
	m.data[0][3] = 1;
    return OK;
}
int multiplicate_matrixes(my_matrix &res, const my_matrix &m1, const my_matrix &m2)
{
	if (m1.rows < 1 && m1.columns < 1)
		return ERR_BAD_MATRIX;
	if (m2.rows < 1 && m2.columns < 1)
		return ERR_BAD_MATRIX;
    if (m1.columns != m2.rows)
    {
        return ERR_MATRIX_MULTI;
    }

	int rc = create_matrix(res, m1.rows, m2.columns);
	if (rc != OK)
		return rc;

    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m2.columns; j++)
        {
            for (int k = 0; k < m1.columns; k++)
            {
				res.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
        }
    }
    return OK;
}
