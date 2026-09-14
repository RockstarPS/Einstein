var ENET_LLD =
[
    [ "Enet LLD Introduction", "enetlld_top.html", [
      [ "Introduction", "enetlld_top.html#enetlld_intro", null ],
      [ "Application Programming Interface", "enetlld_top.html#enetlld_api_overview", [
        [ "Control path API", "enetlld_top.html#autotoc_md1700", null ],
        [ "Data path (DMA) API", "enetlld_top.html#autotoc_md1701", null ],
        [ "Life cycle of an Enet LLD based application", "enetlld_top.html#autotoc_md1702", null ]
      ] ],
      [ "Enet Peripherals", "enetlld_top.html#enetlld_enetpers", [
        [ "CPSW Peripheral", "enetlld_top.html#enetper_cpsw", null ]
      ] ],
      [ "Document Revision History", "enetlld_top.html#enetlld_hist", null ]
    ] ],
    [ "Enet LLD IOCTL interface", "enet_ioctl_interface.html", [
      [ "Introduction", "enet_ioctl_interface.html#enet_ioctl_intro", [
        [ "Using the IOCTL interface", "enet_ioctl_interface.html#using_enet_ioctl", null ],
        [ "Synchronous and Asynchronous IOCTLs", "enet_ioctl_interface.html#enet_async_ioctl", null ]
      ] ]
    ] ],
    [ "Ethernet PHY Link Configuration", "enetphy_link_config_top.html", [
      [ "Link Configuration Guidelines", "enetphy_link_config_top.html#enetphy_link_config_guidelines", [
        [ "Manual Mode", "enetphy_link_config_top.html#enetphy_link_manual", [
          [ "Enabling ECC for R5 Cache memories", "EXAMPLES_SDL_ECC_R5F_CACHE.html#autotoc_md1557", null ],
          [ "Initializing ECC and ESM", "EXAMPLES_SDL_ECC_R5F_CACHE.html#autotoc_md1558", null ],
          [ "Error Injection in I-Cache", "EXAMPLES_SDL_ECC_R5F_CACHE.html#autotoc_md1559", null ],
          [ "Error Injection in D-Cache", "EXAMPLES_SDL_ECC_R5F_CACHE.html#autotoc_md1560", null ],
          [ "Memory Allocation", "EXAMPLES_SDL_ECC_R5F_CACHE.html#autotoc_md1561", null ],
          [ "Half-Duplex Mode", "enetphy_link_config_top.html#enetphy_link_manual_half_duplex", null ],
          [ "Full-Duplex Mode", "enetphy_link_config_top.html#enetphy_link_manual_full_duplex", null ]
        ] ],
        [ "Auto-Negotiation Mode", "enetphy_link_config_top.html#enetphy_link_autoneg", null ],
        [ "Strapping", "enetphy_link_config_top.html#enetphy_link_strapping", null ]
      ] ]
    ] ],
    [ "Ethernet PHY Integration Guide", "phy_integration_guide_top.html", "phy_integration_guide_top" ],
    [ "MAC2MAC support", "enet_mac2mac_top.html", [
      [ "Introduction", "enet_mac2mac_top.html#mac2mac_intro", null ],
      [ "Enable MAC2MAC through Sysconfig", "enet_mac2mac_top.html#mac2mac_syscfg_support", null ]
    ] ],
    [ "Enet Integration Guide", "enet_integration_guide_top.html", [
      [ "Introduction", "enet_integration_guide_top.html#cpsw_integration_guide_intro", null ],
      [ "Getting Familiar with Enet LLD APIs", "enet_integration_guide_top.html#GettingFamiliarWithAPIs", [
        [ "IOCTL Interface", "enet_integration_guide_top.html#IOCTL_description", null ]
      ] ],
      [ "Integrating Enet LLD into User's Application", "enet_integration_guide_top.html#enet_integration_in_app", [
        [ "Init Sequence", "enet_integration_guide_top.html#enet_init_sequence", null ],
        [ "Peripheral Open Sequence", "enet_integration_guide_top.html#enet_open_sequence", null ],
        [ "Port Open Sequence", "enet_integration_guide_top.html#enet_openport_sequence", [
          [ "MAC-PHY link", "enet_integration_guide_top.html#autotoc_md1703", null ],
          [ "MAC-to-MAC link", "enet_integration_guide_top.html#autotoc_md1704", null ]
        ] ],
        [ "Packet Send/Receive Sequence", "enet_integration_guide_top.html#enet_pktrxtx_sequence", null ],
        [ "IOCTL Sequence", "enet_integration_guide_top.html#enet_ioctl_sequence", null ],
        [ "Port Close Sequence", "enet_integration_guide_top.html#enet_closeport_sequence", null ],
        [ "Peripheral Close Sequence", "enet_integration_guide_top.html#enet_close_sequence", null ],
        [ "Deinit Sequence", "enet_integration_guide_top.html#enet_deinit_sequence", null ],
        [ "Peripheral-specific", "enet_integration_guide_top.html#enetper_specific_handling", null ]
      ] ]
    ] ],
    [ "MDIO Manual Mode Enablement", "enetmdio_manualmode.html", [
      [ "Workaround for details errata i2329-MDIO interface corruption and its impact:", "enetmdio_manualmode.html#autotoc_md1705", null ],
      [ "Limitations", "enetmdio_manualmode.html#autotoc_md1706", null ],
      [ "Not supported MDIO IOCTL APIs in MDIO Manual mode", "enetmdio_manualmode.html#autotoc_md1707", null ]
    ] ],
    [ "Version Updates from earlier SDKs to Latest", "enet_mcupsdk_update.html", [
      [ "While upgrading from 11.01 or earlier to latest SDK", "enet_mcupsdk_update.html#autotoc_md1727", [
        [ "Change Set", "enet_mcupsdk_update.html#autotoc_md1728", [
          [ "Change-1 Description", "enet_mcupsdk_update.html#autotoc_md1729", null ],
          [ "Change-1 Impact", "enet_mcupsdk_update.html#autotoc_md1730", null ],
          [ "Change-2 Description", "enet_mcupsdk_update.html#autotoc_md1731", null ],
          [ "Change-2 Impact", "enet_mcupsdk_update.html#autotoc_md1732", null ]
        ] ]
      ] ],
      [ "While upgrading from 11.00 SDK to 11.01 SDK", "enet_mcupsdk_update.html#autotoc_md1733", [
        [ "Change Set", "enet_mcupsdk_update.html#autotoc_md1734", [
          [ "Change-1 Description", "enet_mcupsdk_update.html#autotoc_md1735", null ]
        ] ]
      ] ],
      [ "EthFw 11.1 Changes", "enet_mcupsdk_update.html#autotoc_md1736", [
        [ "Change Set", "enet_mcupsdk_update.html#autotoc_md1737", [
          [ "Change-1 Description", "enet_mcupsdk_update.html#autotoc_md1738", null ],
          [ "Change-2 Description", "enet_mcupsdk_update.html#autotoc_md1739", null ]
        ] ]
      ] ],
      [ "While upgrading from 10.00 SDK", "enet_mcupsdk_update.html#autotoc_md1740", [
        [ "Change Set", "enet_mcupsdk_update.html#autotoc_md1741", [
          [ "Change-1 Description", "enet_mcupsdk_update.html#autotoc_md1742", null ],
          [ "Change-1 Impact", "enet_mcupsdk_update.html#autotoc_md1743", null ],
          [ "Change-1 Solution", "enet_mcupsdk_update.html#autotoc_md1744", null ],
          [ "Change-2 Description", "enet_mcupsdk_update.html#autotoc_md1745", null ],
          [ "Change-2 Impact", "enet_mcupsdk_update.html#autotoc_md1746", null ],
          [ "Change-2 Solution", "enet_mcupsdk_update.html#autotoc_md1747", null ]
        ] ]
      ] ],
      [ "While upgrading from 09.02 SDK or earlier", "enet_mcupsdk_update.html#autotoc_md1748", [
        [ "Change-1 Description", "enet_mcupsdk_update.html#autotoc_md1749", null ],
        [ "Change-1 Impact", "enet_mcupsdk_update.html#autotoc_md1750", null ],
        [ "Change-1 Solution", "enet_mcupsdk_update.html#autotoc_md1751", [
          [ "Option 1:", "enet_mcupsdk_update.html#autotoc_md1752", null ],
          [ "Option 2:", "enet_mcupsdk_update.html#autotoc_md1753", null ]
        ] ],
        [ "Change-2 Description", "enet_mcupsdk_update.html#autotoc_md1754", null ],
        [ "Change-2 Impact", "enet_mcupsdk_update.html#autotoc_md1755", null ],
        [ "Change-2 Solution", "enet_mcupsdk_update.html#autotoc_md1756", null ]
      ] ]
    ] ],
    [ "Ethernet Performance on AM62P", "enetlld_performance.html", [
      [ "Introduction", "enetlld_performance.html#autotoc_md1717", null ],
      [ "Setup Details", "enetlld_performance.html#autotoc_md1718", null ],
      [ "Layer 2 Performance", "enetlld_performance.html#autotoc_md1719", [
        [ "Configuration Details", "enetlld_performance.html#autotoc_md1720", null ],
        [ "Layer 2 Latency", "enetlld_performance.html#autotoc_md1721", null ]
      ] ],
      [ "TCP/IP Performance", "enetlld_performance.html#autotoc_md1722", [
        [ "Configuration Details", "enetlld_performance.html#autotoc_md1723", [
          [ "TCP Throughput", "enetlld_performance.html#autotoc_md1724", null ],
          [ "UDP Throughput", "enetlld_performance.html#autotoc_md1725", null ]
        ] ]
      ] ],
      [ "See Also", "enetlld_performance.html#autotoc_md1726", null ]
    ] ],
    [ "Enet EST/TAS Support", "enet_tas_top.html", [
      [ "Introduction", "enet_tas_top.html#enet_est_intro", [
        [ "IEEE 802.1Qbv EST/TAS", "enet_tas_top.html#enet_est_intro_est_tas", null ],
        [ "Guard band", "enet_tas_top.html#enet_est_intro_guard_band", null ]
      ] ],
      [ "Enet LLD API", "enet_tas_top.html#enet_est_api", null ],
      [ "CPSW Support", "enet_tas_top.html#enet_est_cpsw", null ]
    ] ],
    [ "Enet Migration Guide", "enet_migration_guide_top.html", [
      [ "Introduction", "enet_migration_guide_top.html#enet_migration_guide_intro", null ],
      [ "Need for sysconfig", "enet_migration_guide_top.html#NeedForSysconfig", null ],
      [ "Enet Driver Initialization Sequence Change", "enet_migration_guide_top.html#EnetInitSeqChange", null ],
      [ "Enet DMA channel open changes", "enet_migration_guide_top.html#EnetDmaChOpenChange", null ],
      [ "Runtime Control API (Enet_ioctl) change", "enet_migration_guide_top.html#EnetIoctlChange", null ],
      [ "Packet Transmit/Receive API related changes", "enet_migration_guide_top.html#PacketTxRxChange", null ],
      [ "Custom Board Support", "enet_migration_guide_top.html#CustomBoardSupport", null ],
      [ "External PHY management", "enet_migration_guide_top.html#ExternalPhyManagement", null ],
      [ "Tuning memory usage of enet driver for non-lwip apps", "enet_migration_guide_top.html#MemoryTuningNonLwip", null ],
      [ "Tuning memory usage of enet driver for lwip apps", "enet_migration_guide_top.html#MemoryTuningLwip", null ]
    ] ]
];