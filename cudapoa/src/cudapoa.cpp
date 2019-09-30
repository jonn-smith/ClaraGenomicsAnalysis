/*
* Copyright (c) 2019, NVIDIA CORPORATION.  All rights reserved.
*
* NVIDIA CORPORATION and its licensors retain all intellectual property
* and proprietary rights in and to this software, related documentation
* and any modifications thereto.  Any use, reproduction, disclosure or
* distribution of this software and related documentation without an express
* license agreement from NVIDIA CORPORATION is strictly prohibited.
*/

#include <claragenomics/cudapoa/cudapoa.hpp>
#include <claragenomics/logging/logging.hpp>

#include <vector>

namespace claragenomics
{
namespace cudapoa
{

StatusType Init()
{
    if (logging::LoggingStatus::success != logging::Init())
        return StatusType::generic_error;

    return StatusType::success;
}

::std::string getStatusTypeString(const StatusType& t)
{
    const static char* rawStatusStrings[] = {
        "success",
        "exceeded_maximum_poas",
        "exceeded_maximum_sequence_size",
        "exceeded_maximum_sequences_per_poa",
        "exceeded_batch_size",
        "node_count_exceeded_maximum_graph_size",
        "edge_count_exceeded_maximum_graph_size",
        "seq_len_exceeded_maximum_nodes_per_window",
        "loop_count_exceeded_upper_bound",
        "output_type_unavailable",
        "generic_error"
    };
    const static ::std::vector<::std::string> statusTypeStrings(rawStatusStrings, rawStatusStrings + 11);
    if ( (int)t >= statusTypeStrings.size() ) 
    {
        throw ::std::runtime_error( "Given status type is unknown: " + (int)t );
    } 

    return statusTypeStrings[t];
}


} // namespace cudapoa
} // namespace claragenomics
