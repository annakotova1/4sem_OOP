#include "edge.hpp"

int download_edge(edge_t &result, FILE *file)
{
    char sc;
    if (!file)
        return ERR_ARGS;
    int rc = fscanf(file, "%d ", &result.id1);
    if (rc != 1)
        return END_READ;
    rc = fscanf(file, "%d\n", &result.id2);
    if (rc != 1 || result.id2 == result.id1)
        return ERR_FILE_BAD;
    rc = fscanf(file, "%c", &sc);
    if (rc != 1 || sc != ';')
        return ERR_FILE_BAD;
    return OK;
}
int draw_edge(const dot_t &draw_point1, const dot_t &draw_point2, command_settings_t settings)
{
    settings.picture->getLine(draw_point1.x, draw_point1.y, draw_point2.x, draw_point2.y);
    return OK;
}

void output_edge(edge_t &result)
{
    printf("\t\t\tedge: %d %d\n", result.id1, result.id2);
}