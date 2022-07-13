//
// Created by 董子雄 on 2021/8/2.
//

#ifndef CPP_FEATURE_GRAPH_H
#define CPP_FEATURE_GRAPH_H

#include <numeric>

namespace algorithms {

/**
 * @brief 用来校验 JobRill 是否为只有一个 source job 的有向无环图的工具类
 */
class Graph {
public:
    /**
     * @brief 添加一个顶点
     * @param vid 顶点编号，主要用于检查
     * @return
     */
    bool add_vertex(unsigned vid) {
        if (vid == m_num_vertex) {
            m_num_vertex++;
            for (auto&& row: m_conn_matrix) {
                row.push_back(false);
            }
            m_conn_matrix.emplace_back(m_num_vertex, false);
            _source_vetexes = _get_source_vetexes();
            _sink_vetexes = _get_sink_vetexes();
            return true;
        }
        return false;
    }

    /**
     * @brief 顶点数
     * @return
     */
    unsigned num_vertex() const {
        return m_num_vertex;
    }

    /**
     * @brief 在连通矩阵中添加一条边，首先会检查添加这条边是否会构成环
     * @param from_vid 出顶点
     * @param to_vid 入顶点
     * @return true 添加边成功；false 添加边失败
     */
    bool add_edge(unsigned from_vid, unsigned to_vid) {
        if (from_vid < m_num_vertex
                && to_vid < m_num_vertex
                && from_vid != to_vid
                && !m_conn_matrix[to_vid][from_vid]) {
            m_conn_matrix[from_vid][to_vid] = true;
            // 所有能单向连通 from_vid 的 vid，也设置其单向连通 to_vid
            // 所有 to_vid 能连通到的 vid，也设置 from_vid 能连通到
            for (unsigned i = 0; i < m_num_vertex; i++) {
                if (m_conn_matrix[i][from_vid]) {
                    m_conn_matrix[i][to_vid] = true;
                }
                if (m_conn_matrix[to_vid][i]) {
                    m_conn_matrix[from_vid][i] = true;
                }
            }
            _source_vetexes = _get_source_vetexes();
            _sink_vetexes = _get_sink_vetexes();
            return true;
        }
        return false;
    }

    /**
     * @brief 获取输入顶点索引
     * @return
     */
    const std::vector<unsigned>& source_vetexes() const {
        return _source_vetexes;
    }

    /**
     * @brief 获取输出顶点索引
     * @return
     */
    const std::vector<unsigned>& sink_vetexes() const {
        return _sink_vetexes;
    }

protected:

    /**
     * @brief 获取所有入度为 0 的顶点编号
     * @return
     */
    std::vector<unsigned> _get_source_vetexes() {
        // 对所有的行进行 OR 操作（即对每列所有元素进行 OR），最终投影到一个 vector 上
        std::vector<bool> vertex_vec(m_num_vertex);
        for (auto&& v: m_conn_matrix) {
            std::transform(vertex_vec.begin(), vertex_vec.end(), v.begin(),
                    vertex_vec.begin(), std::logical_or<bool>());
        }
        // 这个 vector 上所有 false 的顶点，就是入度为 0 的顶点
        std::vector<unsigned> vertexes;
        for (unsigned i = 0; i < vertex_vec.size(); i++) {
            if (!vertex_vec[i]) {
                vertexes.push_back(i);
            }
        }
        return vertexes;
    }

    /**
     * @brief 获取所有出度为 0 的顶点编号
     * @return
     */
    std::vector<unsigned> _get_sink_vetexes() {
        // 对所有的列进行 OR 操作（即对每行所有元素进行 OR），最终投影到一个 vector 上
        std::vector<bool> vertex_vec(m_num_vertex);
        for (size_t i = 0; i < m_conn_matrix.size(); i++) {
            vertex_vec[i] = std::accumulate(m_conn_matrix[i].begin(),
                    m_conn_matrix[i].end(),
                    false,
                    std::logical_or<bool>());
        }
        // 这个 vector 上所有 false 的顶点，就是出度为 0 的顶点
        std::vector<unsigned> vertexes;
        for (unsigned i = 0; i < vertex_vec.size(); i++) {
            if (!vertex_vec[i]) {
                vertexes.push_back(i);
            }
        }
        return vertexes;
    }

protected:
    // 连通矩阵的 [i][j] 元素为 true，代表 i 号顶点到 j 号顶点存在单向连通通路
    std::vector <std::vector<bool>> m_conn_matrix;      //!< 连通矩阵
    unsigned m_num_vertex{0};   //!< DAG 顶点总数
    std::vector<unsigned> _source_vetexes;    //!< DAG 的输入顶点列表
    std::vector<unsigned> _sink_vetexes;      //!< DAG 的输出顶点列表
};

}
#endif //CPP_FEATURE_GRAPH_H
