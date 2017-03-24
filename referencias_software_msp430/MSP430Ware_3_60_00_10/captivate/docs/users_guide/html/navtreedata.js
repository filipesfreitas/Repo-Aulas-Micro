var NAVTREE =
[
  [ "CapTIvate™ Technology Guide", "index.html", [
    [ "Getting Started", "ch_get_started.html", null ],
    [ "Introduction", "ch_intro.html", null ],
    [ "Capacitive Sensing Basics", "ch_basics.html", [
      [ "Self Capacitance", "ch_basics.html#ch_basic_self_cap", [
        [ "Self Capacitance Parasitics", "ch_basics.html#ch_basic_self_parasitics", null ],
        [ "Parasitics and the E-Field", "ch_basics.html#ch_basic_self_e_field", null ],
        [ "E-Field Propagation", "ch_basics.html#ch_basic_self_e_field_propagation", null ],
        [ "Self Capacitance Summary", "ch_basics.html#ch_basic_self_summary", null ]
      ] ],
      [ "Mutual Capacitance", "ch_basics.html#ch_basic_mutual_cap", [
        [ "Mutual Capacitance Parasitics", "ch_basics.html#ch_basic_mutual_parasitics", null ],
        [ "Tightly Coupled E-Fields", "ch_basics.html#ch_basic_mutual_e_fields", null ],
        [ "Overlay Material Requirement", "ch_basics.html#ch_basic_mutual_overlay", null ],
        [ "Mutual Capacitance Sensitivity", "ch_basics.html#ch_basic_mutual_sensitivity", null ],
        [ "Mutual Capacitance Summary", "ch_basics.html#ch_basic_mutual_summary", null ]
      ] ],
      [ "True Matrix Capability", "ch_basics.html#ch_basic_mutual_matrix", null ]
    ] ],
    [ "Technology", "ch_tech.html", [
      [ "Charge Transfer Technology", "ch_tech.html#ch_tech_charge_transfer", [
        [ "Charge and Transfer Phases in Self Mode", "ch_tech.html#ch_tech_self_CT_phases", null ],
        [ "Mutual Mode Charge and Transfer Phases", "ch_tech.html#ch_tech_mutual_CT_phases", null ]
      ] ],
      [ "The CapTIvate™ Peripheral", "ch_tech.html#ch_tech_Peripheral", [
        [ "Capacitance Measurement", "ch_tech.html#ch_tech_PeripheralMeasurement", [
          [ "IO Mux", "ch_tech.html#ch_tech_IOMux", null ]
        ] ],
        [ "Auxillary Digital Functions", "ch_tech.html#ch_tech_captivatePeripheral_aux_dig_funcs", [
          [ "Low Power Operation", "ch_tech.html#ch_tech_captivatePeripheral_aux_dig_funcs_low_power", [
            [ "CapTIvate™Timer", "ch_tech.html#ch_tech_captivatePeripheral_aux_dig_funcs_low_power_timer", null ],
            [ "Finite State Machine (FSM)", "ch_tech.html#ch_tech_captivatePeripheral_aux_dig_funcs_low_power_timer_FSM", null ],
            [ "Wake on Touch Operation (WOT)", "ch_tech.html#ch_tech_captivatePeripheral_aux_dig_funcs_low_power_timer_WOT", null ]
          ] ],
          [ "Conversion Timing", "ch_tech.html#ch_tech_captivatePeripheral_Timing", null ],
          [ "EMC", "ch_tech.html#ch_tech_captivatePeripheral_EMC", [
            [ "Emissions", "ch_tech.html#ch_tech_captivatePeripheral_EMC_emissions", null ],
            [ "Susceptibility", "ch_tech.html#ch_tech_captivatePeripheral_EMC_susceptibility", null ]
          ] ],
          [ "Reference Capacitors", "ch_tech.html#ch_tech_captivatePeripheral_REFCAP", null ]
        ] ]
      ] ]
    ] ],
    [ "Design Guide", "ch_design.html", [
      [ "Introduction", "ch_design.html#ch_design_intro", null ],
      [ "Starting a New Design", "ch_design.html#ch_design_start", null ],
      [ "Design Process", "ch_design.html#ch_design_process", null ],
      [ "Best Practices", "ch_design.html#ch_design_best_practices", [
        [ "Mechanicals", "ch_design.html#ch_design_mechanicals", null ],
        [ "Common Layout Considerations", "ch_design.html#ch_design_common", [
          [ "Routing", "ch_design.html#ch_design_common_routing", null ],
          [ "Electrode Material", "ch_design.html#ch_design_self_electrode_material", null ],
          [ "Spacing Between Electrodes", "ch_design.html#ch_design_self_electrode_spacing", null ],
          [ "Shapes", "ch_design.html#ch_design_self_shape", null ],
          [ "Crosstalk", "ch_design.html#ch_design_common_crosstalk", null ],
          [ "Adjacent Capacitive Touch Signals", "ch_design.html#ch_design_common_other", null ],
          [ "Digital Signals", "ch_design.html#ch_design_common_digital_signals", null ],
          [ "LEDs/LED Backlighting", "ch_design.html#ch_design_common_leds", null ],
          [ "Ground Planes", "ch_design.html#ch_design_self_ground_planes", null ],
          [ "Separation", "ch_design.html#ch_design_self_ground_separation", null ],
          [ "Pour", "ch_design.html#ch_design_self_ground_pour", null ],
          [ "Mutual Capacitance Traces", "ch_design.html#ch_design_mutual_routing", null ]
        ] ]
      ] ],
      [ "Buttons", "ch_design.html#ch_design_buttons", [
        [ "Self Capacitive Buttons", "ch_design.html#ch_design_self_buttons", [
          [ "Self Capacitive Button Shapes", "ch_design.html#ch_design_self_button_shape", null ]
        ] ],
        [ "Mutual Capacitive Buttons", "ch_design.html#ch_design_mutual_buttons", [
          [ "Mutual Capacitive Button Shapes", "ch_design.html#ch_design_mutual_button_shape", null ]
        ] ]
      ] ],
      [ "Sliders and Wheels", "ch_design.html#ch_design_sliders_wheels", [
        [ "Slider and Wheel Resolution", "ch_design.html#ch_design_slider_wheel_resolution", null ],
        [ "Self Capacitive Sensor Shapes", "ch_design.html#ch_design_self_slider_wheel", [
          [ "Self Capacitive Slider", "ch_design.html#ch_design_self_slider", null ],
          [ "Self Capacitive Wheel", "ch_design.html#ch_design_self_wheel", null ]
        ] ],
        [ "Mutual Capacitive Sensor Shapes", "ch_design.html#ch_design_mutual_slider_wheel", [
          [ "Mutual Capacitive Slider", "ch_design.html#ch_design_mutual_slider", null ],
          [ "Mutual Capacitive Wheel", "ch_design.html#ch_design_mutual_wheel", null ]
        ] ]
      ] ],
      [ "Proximity", "ch_design.html#ch_design_proximity", [
        [ "Proximity Shapes", "ch_design.html#ch_design_proximity_shapes", null ]
      ] ],
      [ "Ultra Low Power", "ch_design.html#ch_design_low_power", [
        [ "Introduction", "ch_design.html#ch_design_low_power_intro", null ],
        [ "Expectations", "ch_design.html#ch_design_low_power_expectations", null ],
        [ "Optimization Steps", "ch_design.html#ch_design_low_power_optimization", [
          [ "Selecting a Low Frequency Clock", "ch_design.html#ch_design_low_power_optimization_clock", null ],
          [ "Optimizing the Application Scan Period", "ch_design.html#ch_design_low_power_optimization_scanperiod", null ],
          [ "Optimizing for the Smallest Parasitic Capacitance", "ch_design.html#ch_design_low_power_optimization_parasitics", null ],
          [ "Optimizing for the Shortest Measurement Time", "ch_design.html#ch_design_low_power_optimization_meastime", null ],
          [ "Using the Wake-on-Proximity State Machine Effectively", "ch_design.html#ch_design_low_power_optimization_statemachine", null ]
        ] ],
        [ "Walking Through the Optimization Process", "ch_design.html#ch_design_low_power_example", null ],
        [ "A Note about Mutual Capacitance and Bias Current", "ch_design.html#ch_design_low_power_bias_current", null ]
      ] ],
      [ "Moisture", "ch_design.html#ch_design_moisture", [
        [ "Introduction", "ch_design.html#ch_design_moisture_intro", null ],
        [ "Expectations", "ch_design.html#ch_design_moisture_expectations", null ],
        [ "Moisture Physics", "ch_design.html#ch_design_moisture_physics", null ],
        [ "Moisture Problems", "ch_design.html#ch_design_moisture_problems", null ],
        [ "Moisture Mitigation Techniques", "ch_design.html#ch_design_moisture_mitigation", [
          [ "Moisture Tolerance Applications", "ch_design.html#ch_design_moisture_mitigation_tolerance", null ],
          [ "Spill Rejection Applications", "ch_design.html#ch_design_moisture_mitigation_rejection", null ]
        ] ]
      ] ],
      [ "Noise Immunity", "ch_design.html#ch_design_noise", [
        [ "Introduction", "ch_design.html#ch_design_noise_intro", [
          [ "How to Use This Section", "ch_design.html#ch_design_noise_intro_howtouse", null ],
          [ "Additional Resources", "ch_design.html#ch_design_noise_intro_resources", null ],
          [ "Aggressor-Victim Philosophy", "ch_design.html#ch_design_noise_intro_agressorvictim", null ]
        ] ],
        [ "The Three Sided Approach", "ch_design.html#ch_design_noise_intro_threesidedapproach", [
          [ "Introduction to Electromagnetic Compatibility (EMC) Standards", "ch_design.html#ch_design_noise_intro_emcstandards", null ],
          [ "Signal-to-Noise Ratio", "ch_design.html#ch_design_noise_intro_snr", null ]
        ] ],
        [ "Types of Noise", "ch_design.html#ch_design_noise_types", [
          [ "Differential Mode Supply Rail Noise", "ch_design.html#ch_design_noise_types_diffmodesupplynoise", [
            [ "Problem", "ch_design.html#ch_noiseimmunity_diffmodesupplynoise_problem", null ],
            [ "CapTIvate™ MCU Solution", "ch_design.html#ch_design_noise_types_diffmodesupplynoise_solution", null ],
            [ "Design Actions Required", "ch_design.html#ch_design_noise_types_diffmodesupplynoise_actions", null ]
          ] ],
          [ "Electrostatic Discharge (ESD)", "ch_design.html#ch_design_noise_types_esd", [
            [ "Problem", "ch_design.html#ch_noiseimmunity_esd_problem", null ],
            [ "CapTIvate™ MCU Solution", "ch_design.html#ch_design_noise_types_esd_solution", null ],
            [ "Design Actions Required", "ch_design.html#ch_design_noise_types_esd_actions", null ]
          ] ],
          [ "Electrical Fast Transient (EFT)", "ch_design.html#ch_design_noise_types_eft", [
            [ "Expectations", "ch_design.html#ch_design_noise_types_eft_expectations", null ],
            [ "Problem", "ch_design.html#ch_design_noise_types_eft_problem", null ],
            [ "CapTIvate™ MCU Solution", "ch_design.html#ch_design_noise_types_eft_solution", null ],
            [ "Design Actions Required", "ch_design.html#ch_noiseimmunity_eft_actions", null ]
          ] ],
          [ "RF Susceptibility (Conducted and Radiated)", "ch_design.html#ch_design_noise_types_rfimmunity", [
            [ "Expectations", "ch_design.html#ch_design_noise_types_rfimmunity_expectations", null ],
            [ "Conducted RF Noise Test System", "ch_design.html#ch_design_noise_types_rfimmunity_testsystem", null ],
            [ "Problem", "ch_design.html#ch_design_noise_types_rfimmunity_problem", null ],
            [ "CapTIvate™ MCU Solution", "ch_design.html#ch_design_noise_types_rfimmunity_solution", null ],
            [ "Design Actions Required", "ch_design.html#ch_design_noise_types_rfimmunity_actions", null ]
          ] ]
        ] ],
        [ "Noise Mitigation Steps", "ch_design.html#ch_design_noise_mitigation", [
          [ "Self versus Mutual Capacitance for Noise Immunity", "ch_design.html#ch_design_noise_mitigation_selfvmutual", null ],
          [ "Noise Immunity Hardware Check List", "ch_design.html#ch_design_noise_mitigation_hardware", [
            [ "Noise Immunity Electrode Design Best Practices", "ch_design.html#ch_design_noise_mitigation_hardware_electrodes", null ],
            [ "Noise Immunity Electrode Shielding Best Practices", "ch_design.html#ch_design_noise_mitigation_hardware_shielding", null ]
          ] ],
          [ "Tuning Check List", "ch_design.html#ch_design_noise_mitigation_tuning", null ]
        ] ]
      ] ],
      [ "References", "ch_design.html#ch_design_references", null ]
    ] ],
    [ "Design Center GUI", "DesignCenter.html", [
      [ "Introduction", "DesignCenter.html#ch_cdc_Intro", [
        [ "Key features", "DesignCenter.html#ch_cdc_Intro_sec01", null ],
        [ "Hardware and software requirements", "DesignCenter.html#ch_cdc_Intro_sec02", [
          [ "Additional Linux requirements", "DesignCenter.html#ch_cdc_Intro_sec02_02", null ]
        ] ],
        [ "Licensing", "DesignCenter.html#ch_cdc_Intro_sec03", null ]
      ] ],
      [ "CapTIvate™ Design Center Quick start", "DesignCenter.html#ch_cdc_QuickStart", [
        [ "Start the Design Center", "DesignCenter.html#ch_cdc_QuickStart_sec01", null ],
        [ "Place the sensors", "DesignCenter.html#ch_cdc_QuickStart_sec02", null ],
        [ "Place the MSP430 controller", "DesignCenter.html#ch_cdc_QuickStart_sec03", null ],
        [ "Connect sensors to MSP430 capacitive touch I/O ports", "DesignCenter.html#ch_cdc_QuickStart_sec04", null ],
        [ "Generate source code", "DesignCenter.html#ch_cdc_QuickStart_sec05", null ],
        [ "Load and run the MSP430FR26xx/25xx generated firmware project using CCS or IAR", "DesignCenter.html#ch_cdc_QuickStart_sec06", null ],
        [ "Communicating with the target", "DesignCenter.html#ch_cdc_QuickStart_sec07", null ]
      ] ],
      [ "CapTIvate™ Design Center Users guide", "DesignCenter.html#ch_cdc_UsersGuide", [
        [ "Design Center GUI panels", "DesignCenter.html#ch_cdc_UsersGuide_sec01", [
          [ "Menu bar", "DesignCenter.html#ch_cdc_UsersGuide_sec01_01", null ],
          [ "Object Selection Tab", "DesignCenter.html#ch_cdc_UsersGuide_sec01_02", null ],
          [ "Miscellaneous Selection Tab", "DesignCenter.html#ch_cdc_UsersGuide_sec01_02A", null ],
          [ "Design Canvas", "DesignCenter.html#ch_cdc_UsersGuide_sec01_03", null ]
        ] ],
        [ "Menu Descriptions", "DesignCenter.html#ch_cdc_UsersGuide_sec02", [
          [ "File", "DesignCenter.html#ch_cdc_UsersGuide_sec02_01", [
            [ "Print", "DesignCenter.html#ch_cdc_UsersGuide_sec02_01_01", null ],
            [ "Project Open/Save/SaveAs", "DesignCenter.html#ch_cdc_UsersGuide_sec02_01_02", null ],
            [ "Switch Workspace", "DesignCenter.html#ch_cdc_UsersGuide_sec02_01_03", null ],
            [ "Exit", "DesignCenter.html#ch_cdc_UsersGuide_sec02_01_04", null ]
          ] ],
          [ "Edit", "DesignCenter.html#ch_cdc_UsersGuide_sec02_02", [
            [ "Undo/Redo", "DesignCenter.html#ch_cdc_UsersGuide_sec02_02_01", null ],
            [ "Cut", "DesignCenter.html#ch_cdc_UsersGuide_sec02_02_01_02", null ],
            [ "Select All", "DesignCenter.html#ch_cdc_UsersGuide_sec02_02_03", null ]
          ] ],
          [ "Options", "DesignCenter.html#ch_cdc_UsersGuide_sec02_03", [
            [ "Display", "DesignCenter.html#ch_cdc_UsersGuide_sec02_03_01", null ],
            [ "Features", "DesignCenter.html#ch_cdc_UsersGuide_sec02_03_02", null ]
          ] ],
          [ "Communications", "DesignCenter.html#ch_cdc_UsersGuide_sec02_04", [
            [ "Connect/Disconnect", "DesignCenter.html#ch_cdc_UsersGuide_sec02_04_01", null ],
            [ "Settings - HID", "DesignCenter.html#ch_cdc_UsersGuide_sec02_04_02", null ],
            [ "Settings - Logging", "DesignCenter.html#ch_cdc_UsersGuide_sec02_04_03", null ]
          ] ],
          [ "Help", "DesignCenter.html#ch_cdc_UsersGuide_sec02_05", null ],
          [ "Topics", "DesignCenter.html#ch_cdc_UsersGuide_sec02_05_01", null ],
          [ "About", "DesignCenter.html#ch_cdc_UsersGuide_sec02_05_02", null ]
        ] ],
        [ "Controller Properties", "DesignCenter.html#ch_cdc_UsersGuide_sec03", [
          [ "Device configuration", "DesignCenter.html#ch_cdc_UsersGuide_sec03_01", null ],
          [ "Enable target communications and target MCU communications interface", "DesignCenter.html#ch_cdc_UsersGuide_sec03_02", null ],
          [ "Select Compile Time options", "DesignCenter.html#ch_cdc_UsersGuide_sec03_compile_options", null ],
          [ "Mapping sensor ports to controller pins", "DesignCenter.html#ch_cdc_UsersGuide_sec03_03", [
            [ "Auto-assign", "DesignCenter.html#ch_cdc_UsersGuide_sec03_03_01", null ],
            [ "Manual mapping using the Configure Connections table", "DesignCenter.html#ch_cdc_UsersGuide_sec03_03_02", null ],
            [ "Port column edits", "DesignCenter.html#ch_cdc_UsersGuide_sec03_03_02_01", null ],
            [ "Parallel Block column edits", "DesignCenter.html#ch_cdc_UsersGuide_sec03_03_02_02", null ],
            [ "Sensor column edits", "DesignCenter.html#ch_cdc_UsersGuide_sec03_03_02_03", null ]
          ] ],
          [ "Making manual connections graphically", "DesignCenter.html#ch_cdc_UsersGuide_sec03_03_03", null ],
          [ "Source Code Generation", "DesignCenter.html#ch_cdc_UsersGuide_sec03_04", [
            [ "Create new project", "DesignCenter.html#ch_cdc_UsersGuide_sec03_04_01", null ],
            [ "Update existing project", "DesignCenter.html#ch_cdc_UsersGuide_sec03_04_02", null ]
          ] ],
          [ "Controller target data displays", "DesignCenter.html#ch_cdc_UsersGuide_sec03_05", [
            [ "Controller Channel Bar Chart", "DesignCenter.html#ch_cdc_UsersGuide_sec03_05_01", null ],
            [ "Controller Channel Table", "DesignCenter.html#ch_cdc_UsersGuide_sec03_05_02", null ]
          ] ],
          [ "Controller Conversion Control parameters", "DesignCenter.html#ch_cdc_UsersGuide_sec03_06", null ],
          [ "Controller Scan Time Estimator", "DesignCenter.html#ch_cdc_UsersGuide_sec03_07", null ]
        ] ],
        [ "Sensor Properties", "DesignCenter.html#ch_cdc_UsersGuide_sec04", [
          [ "Position Display", "DesignCenter.html#ch_cdc_UsersGuide_sec04_01", null ],
          [ "Sensor Configuration", "DesignCenter.html#ch_cdc_UsersGuide_sec04_02", [
            [ "Capacitive Mode", "DesignCenter.html#ch_cdc_UsersGuide_sec04_02_01", null ],
            [ "Element Count", "DesignCenter.html#ch_cdc_UsersGuide_sec04_02_02", null ],
            [ "Electrode Configuration", "DesignCenter.html#ch_cdc_UsersGuide_sec04_02_03", null ],
            [ "Configure TX/RX grouping", "DesignCenter.html#ch_cdc_UsersGuide_sec04_02_04", null ]
          ] ],
          [ "Enable Target Communications from Sensor Properties", "DesignCenter.html#ch_cdc_UsersGuide_sec04_03", null ],
          [ "Sensor target data displays", "DesignCenter.html#ch_cdc_UsersGuide_sec04_04", [
            [ "Sensor Channel Bar Chart", "DesignCenter.html#ch_cdc_UsersGuide_sec04_04_01", null ],
            [ "Sensor Oscilloscope Plot", "DesignCenter.html#ch_cdc_UsersGuide_sec04_04_02", null ],
            [ "Sensor Channel Table", "DesignCenter.html#ch_cdc_UsersGuide_sec04_04_03", null ]
          ] ],
          [ "Tuning Sensor performance", "DesignCenter.html#ch_cdc_UsersGuide_sec04_05", null ]
        ] ],
        [ "Displaying Target Data", "DesignCenter.html#ch_cdc_UsersGuide_sec05", [
          [ "Channel Bar Chart", "DesignCenter.html#ch_cdc_UsersGuide_sec05_01", null ],
          [ "Oscilloscope Plot", "DesignCenter.html#ch_cdc_UsersGuide_sec05_02", null ],
          [ "Channel Table", "DesignCenter.html#ch_cdc_UsersGuide_sec05_03", null ]
        ] ],
        [ "SNR Measurements", "DesignCenter.html#ch_cdc_UsersGuide_sec06", null ]
      ] ],
      [ "Loading and running generated projects", "DesignCenter.html#ch_cdc_LoadAndRunProjects", [
        [ "Importing/opening projects", "DesignCenter.html#ch_cdc_LoadAndRunProjects_sec01", [
          [ "Code Composer Studio", "DesignCenter.html#ch_cdc_LoadAndRunProjects_sec01_01", null ],
          [ "IAR Embedded Workbench", "DesignCenter.html#ch_cdc_LoadAndRunProjects_sec01_02", null ]
        ] ],
        [ "Enable target communications in the Design Center", "DesignCenter.html#ch_cdc_LoadAndRunProjects_sec02", null ]
      ] ]
    ] ],
    [ "Device Family", "ch_device.html", [
      [ "Standard Devices", "ch_device.html#ch_device_std", null ],
      [ "Small Form Factor (Die Size) Devices", "ch_device.html#ch_device_small", null ]
    ] ],
    [ "Software Library", "ch_lib.html", [
      [ "Introduction", "ch_lib.html#ch_lib_intro", [
        [ "Using This Chapter", "ch_lib.html#ch_lib_introduction_usingthischapter", null ],
        [ "Device and Tools Support", "ch_lib.html#ch_lib_introduction_support", null ],
        [ "Delivery Mechanism", "ch_lib.html#ch_lib_introduction_delivery", null ],
        [ "Change Control", "ch_lib.html#ch_lib_introduction_changecontrol", null ]
      ] ],
      [ "Overview", "ch_lib.html#ch_lib_overview", [
        [ "Programming Model", "ch_lib.html#ch_lib_overview_model", null ],
        [ "Organization and Architecture", "ch_lib.html#ch_lib_overview_organization", null ]
      ] ],
      [ "Getting Started", "ch_lib.html#ch_lib_gettingstarted", [
        [ "Starting from Scratch with the Starter Project", "ch_lib.html#ch_lib_gettingstarted_starterproj", null ],
        [ "Adding CapTIvate™ to an Existing Project", "ch_lib.html#ch_lib_gettingstarted_existingproj", null ]
      ] ],
      [ "How-To", "ch_lib.html#ch_lib_howto", [
        [ "Use the Top Level API", "ch_lib.html#ch_lib_howto_toplevelapi", null ],
        [ "Register a Callback Function", "ch_lib.html#ch_lib_howto_callbacks", null ],
        [ "Access Element State Data", "ch_lib.html#ch_lib_howto_elementstatedata", null ],
        [ "Access the Dominant Button", "ch_lib.html#ch_lib_howto_dominantbutton", null ],
        [ "Access Slider or Wheel Position Data", "ch_lib.html#ch_lib_howto_sliderwheeldata", null ],
        [ "Access Element Measurement Data", "ch_lib.html#ch_lib_howto_elementmeasdata", null ],
        [ "Update Sensors Independently", "ch_lib.html#ch_lib_howto_measuresensors", null ],
        [ "Update a Sensor's Raw Data Only", "ch_lib.html#ch_lib_howto_measureraw", null ],
        [ "Enable an IO as a Shield", "ch_lib.html#ch_lib_howto_shieldIO", null ],
        [ "Create a Custom EMC Configuration", "ch_lib.html#ch_lib_howto_customEMC", null ],
        [ "Stream Unformatted Data to the Design Center GUI", "ch_lib.html#ch_lib_howto_generalpurposedata", null ]
      ] ],
      [ "Technical Details", "ch_lib.html#ch_lib_techdetails", [
        [ "Devices with CapTIvate™ Software in ROM", "ch_lib.html#ch_lib_techdetails_rom", null ],
        [ "MSP430 CPUX Memory Model", "ch_lib.html#ch_lib_techdetails_memmodel", null ]
      ] ],
      [ "Base Module", "ch_lib.html#ch_lib_base", [
        [ "HAL", "ch_lib.html#ch_lib_base_hal", null ],
        [ "Touch", "ch_lib.html#ch_lib_base_touch", [
          [ "Sensor Update Routines", "ch_lib.html#ch_lib_base_touch_sensorupdate", [
            [ "CAPT_updateSensor()", "ch_lib.html#ch_lib_base_touch_sensorupdate_basic", null ],
            [ "CAPT_updateSensorWithEMC()", "ch_lib.html#ch_lib_base_touch_sensorupdate_emc", null ],
            [ "CAPT_updateSensorRawCount()", "ch_lib.html#ch_lib_base_touch_sensorupdate_raw", null ]
          ] ],
          [ "Calibration Algorithms", "ch_lib.html#ch_lib_base_touch_calibrationalgorithms", null ],
          [ "Environmental Drift Algorithms", "ch_lib.html#ch_lib_base_touch_environmentaldriftalgo", null ]
        ] ],
        [ "ISR", "ch_lib.html#ch_lib_base_isr", null ],
        [ "Type Definitions", "ch_lib.html#ch_lib_base_types", null ]
      ] ],
      [ "Advanced Module", "ch_lib.html#ch_lib_advanced", [
        [ "Manager", "ch_lib.html#ch_lib_advanced_manager", null ],
        [ "Buttons", "ch_lib.html#ch_lib_advanced_buttons", null ],
        [ "Sliders and Wheels", "ch_lib.html#ch_lib_advanced_sliderswheels", null ],
        [ "EMC", "ch_lib.html#ch_lib_emc", [
          [ "EMC Module Background", "ch_lib.html#ch_lib_emc_background", null ],
          [ "Using the EMC Module", "ch_lib.html#ch_lib_emc_overview_using", [
            [ "Enabling Noise Immunity (EMC) Features", "ch_lib.html#ch_lib_emc_overview_using_enabling", null ],
            [ "Function Replacements with Noise Immunity Enabled", "ch_lib.html#ch_lib_emc_overview_using_functions", null ],
            [ "EMC Module Configuration", "ch_lib.html#ch_lib_emc_configuration", null ]
          ] ],
          [ "EMC Module Algorithms", "ch_lib.html#ch_lib_emc_algorithms", [
            [ "Multi Frequency Processing (MFP) Algorithm", "ch_lib.html#ch_lib_emc_algorithms_mfp", null ],
            [ "Dynamic Threshold Adjustment (DTA) Algorithm", "ch_lib.html#ch_lib_emc_algorithms_dta", null ]
          ] ]
        ] ]
      ] ],
      [ "Communications Module", "ch_lib.html#ch_lib_communications", [
        [ "Background", "ch_lib.html#ch_lib_communications_background", null ],
        [ "Overview", "ch_lib.html#ch_lib_communications_overview", null ],
        [ "Interface Layer", "ch_lib.html#ch_lib_communications_interface", [
          [ "Using the Communications Module: Initializing the Interface", "ch_lib.html#ch_lib_communications_interface_init", null ],
          [ "Using the Communications Module: Handling Incoming Data", "ch_lib.html#ch_lib_communications_interface_incomingdata", null ],
          [ "Using the Communications Module: Writing Out Data", "ch_lib.html#ch_lib_communications_interface_outgoingdata", null ],
          [ "Compile-Time Configuration", "ch_lib.html#ch_lib_communications_interface_compiletimeconfig", null ]
        ] ],
        [ "Protocol Layer", "ch_lib.html#ch_lib_communications_protocol", [
          [ "Introduction to Packet Types", "ch_lib.html#ch_lib_communications_protocol_packettypes", null ],
          [ "Format: Sensor Packets", "ch_lib.html#ch_lib_communications_protocol_sensorpacket", null ],
          [ "Format: Cycle Packets", "ch_lib.html#ch_lib_communications_protocol_cyclepacket", null ],
          [ "Format: Trackpad Packets", "ch_lib.html#ch_lib_communications_protocol_trackpadpacket", null ],
          [ "Format: General Purpose Packets", "ch_lib.html#ch_lib_communications_protocol_gppacket", null ],
          [ "Format: Parameter Packets", "ch_lib.html#ch_lib_communications_protocol_parameterpacket", null ]
        ] ],
        [ "UART Driver", "ch_lib.html#ch_lib_communications_uartdriver", [
          [ "Purpose of the Driver", "ch_lib.html#ch_lib_comm_uart_purpose", null ],
          [ "Driver Features", "ch_lib.html#ch_lib_comm_uart_features", null ],
          [ "Driver Overview", "ch_lib.html#ch_lib_comm_uart_overview", null ],
          [ "Compile-time Driver Configuration Options", "ch_lib.html#ch_lib_comm_uart_compiletimeconfig", null ],
          [ "Run-time Driver Configuration Options", "ch_lib.html#ch_lib_comm_uart_runtimeconfig", null ],
          [ "Using the Driver: Opening and Closing the Driver", "ch_lib.html#ch_lib_comm_uart_howtoopenandclose", null ],
          [ "Using the Driver: Transmitting Data", "ch_lib.html#ch_lib_comm_uart_howtotx", null ],
          [ "Using the Driver: Receiving Data", "ch_lib.html#ch_lib_comm_uart_howtorx", null ],
          [ "Using the Driver: Error Handling", "ch_lib.html#ch_lib_comm_uart_howtoerrorhandle", null ],
          [ "Using the Driver: Example Application", "ch_lib.html#ch_lib_comm_uart_example1", null ]
        ] ],
        [ "I2C Slave Driver", "ch_lib.html#ch_lib_communications_i2cslavedriver", [
          [ "Purpose of the Driver", "ch_lib.html#ch_lib_comm_i2cslave_purpose", null ],
          [ "Driver Features", "ch_lib.html#ch_lib_comm_i2cslave_features", null ],
          [ "Driver Overview", "ch_lib.html#ch_lib_comm_i2cslave_overview", [
            [ "Driver Overview: I2C Receive Operations (I2C Bus Write)", "ch_lib.html#ch_lib_comm_i2cslave_overview_receiveops", null ],
            [ "Driver Overview: I2C Transmit Operations (I2C Bus Read)", "ch_lib.html#ch_lib_comm_i2cslave_overview_transmitops", null ],
            [ "Driver Overview: Slave Request Feature", "ch_lib.html#ch_lib_comm_i2cslave_overview_slavereqfeature", null ],
            [ "Driver Overview: Timeout Feature (Function Timer)", "ch_lib.html#ch_lib_comm_i2cslave_overview_timeoutfeature", null ]
          ] ],
          [ "Compile-time Driver Configuration Options", "ch_lib.html#ch_lib_comm_i2cslave_compiletimeconfig", null ],
          [ "Run-time Driver Configuration Options", "ch_lib.html#ch_lib_comm_i2cslave_runtimeconfig", null ],
          [ "Using the Driver: Opening and Closing the Driver", "ch_lib.html#ch_lib_comm_i2cslave_howtoopenandclose", null ],
          [ "Using the Driver: Transmitting Data (I2C Read Operation)", "ch_lib.html#ch_lib_comm_i2cslave_howtotransmit", null ],
          [ "Using the Driver: Receiving Data (I2C Write Operation)", "ch_lib.html#ch_lib_comm_i2cslave_howtoreceive", null ],
          [ "Using the Driver: Error Handling", "ch_lib.html#ch_lib_comm_i2cslave_howtohandleerrors", null ],
          [ "Using the Driver: Example Application", "ch_lib.html#ch_lib_comm_i2cslave_example1", null ]
        ] ]
      ] ],
      [ "Benchmarks", "ch_lib.html#ch_lib_benchmarks", [
        [ "Memory Requirements", "ch_lib.html#ch_lib_benchmarks_memoryreq", null ],
        [ "Execution Times", "ch_lib.html#ch_lib_benchmarks_exectimes", null ]
      ] ]
    ] ],
    [ "MSP-CAPT-FR2633 Development Kit", "ch_evm.html", [
      [ "Introduction", "ch_evm.html#ch_evm_intro", [
        [ "Overview", "ch_evm.html#ch_evm_overview", null ],
        [ "Key Features", "ch_evm.html#ch_evm_features", null ]
      ] ],
      [ "Getting Started with the MCU Development Kit", "ch_evm.html#ch_evm_get_started", [
        [ "Pre-Work", "ch_evm.html#ch_evm_get_started_prework", null ],
        [ "Running an Example Project", "ch_evm.html#ch_evm_get_started_loadingexample", null ],
        [ "Example Project Locations", "ch_evm.html#ch_evm_example_project_locations", null ]
      ] ],
      [ "Sensor Panel Demonstrations", "ch_evm.html#ch_evm_get_started_sensorpanels", [
        [ "CAPTIVATE-BSWP Demonstration (Out of Box Experience)", "ch_evm.html#ch_evm_get_started_sensorpanels_bswp", [
          [ "CAPTIVATE-BSWP Bonus Software Projects", "ch_evm.html#ch_evm_get_started_sensorpanels_bswp_bonus", [
            [ "Ultra Low Power Four Buttons Demonstration", "ch_evm.html#ch_evm_get_started_sensorpanels_bswp_bonus_ulp4btn", null ],
            [ "Code Size Optimized One Button Demonstration", "ch_evm.html#ch_evm_get_started_sensorpanels_bswp_bonus_cso1btn", null ]
          ] ]
        ] ],
        [ "CAPTIVATE-PHONE Demonstration", "ch_evm.html#ch_evm_get_started_sensorpanels_phone", null ],
        [ "CAPTIVATE-PROXIMITY Demonstration", "ch_evm.html#ch_evm_get_started_sensorpanels_prox", null ]
      ] ],
      [ "Hardware", "ch_evm.html#ch_evm_hardware", [
        [ "CAPTIVATE-FR2633 Processor PCB Overview", "ch_evm.html#ch_evm_kit_fr2633", [
          [ "Features", "ch_evm.html#ch_evm_kit_fr2633_features", null ]
        ] ],
        [ "CAPTIVATE-PGMR Programmer PCB Overview", "ch_evm.html#ch_evm_hardware_pgmr", [
          [ "Features", "ch_evm.html#ch_evm_kit_pgmr_features", null ]
        ] ],
        [ "CAPTIVATE-ISO (Communications Isolation PCB)", "ch_evm.html#ch_evm_hardware_iso", [
          [ "Features", "ch_evm.html#ch_evm_kit_iso_features", null ]
        ] ],
        [ "CAPTIVATE-BSWP", "ch_evm.html#ch_evm_hardware_bswp", null ],
        [ "CAPTIVATE-PHONE", "ch_evm.html#ch_evm_hardware_phone", null ],
        [ "CAPTIVATE-PROXIMITY", "ch_evm.html#ch_evm_hardware_prox", null ],
        [ "48-pin Male Sensor PCB Connector Information", "ch_evm.html#ch_evm_hardware_connector48", null ]
      ] ],
      [ "Using the HID Bridge", "ch_evm.html#ch_evm_hidbridge", [
        [ "HID Bridge Interfaces", "ch_evm.html#ch_evm_hidbridge_interfaces", null ],
        [ "HID Bridge Configuration Command Set", "ch_evm.html#ch_evm_hidbridge_commandset", null ],
        [ "HID Bridge Modes of Operation", "ch_evm.html#ch_evm_hidbridge_modesofoperation", [
          [ "Operating Mode: Packet Mode", "ch_evm.html#ch_evm_hidbridge_modesofoperation_packet", null ],
          [ "Operating Mode: Raw Mode", "ch_evm.html#ch_evm_hidbridge_modesofoperation_raw", null ]
        ] ]
      ] ]
    ] ],
    [ "Workshop (Getting Started)", "ch_workshop.html", [
      [ "Hardware Setup", "ch_workshop.html#ch_workshop_setup", null ],
      [ "Important note about wake on proximity behavior", "ch_workshop.html#ch_workshop_prox_behavior", [
        [ "Out of Box Experience", "ch_workshop.html#ch_workshop_oobe", null ]
      ] ],
      [ "Creating a new sensor design project", "ch_workshop.html#ch_workshop_new_project", [
        [ "LAB #1", "ch_workshop.html#ch_workshop_lab1", null ],
        [ "Part 1 - Creating a New Design", "ch_workshop.html#ch_workshop_new_design", null ],
        [ "Part 2 - Tuning Sensors", "ch_workshop.html#ch_workshop_tuning_sensors", null ],
        [ "Part 3 - Generate Updated Sensor Configuration", "ch_workshop.html#ch_workshop_lab1_part3", null ]
      ] ],
      [ "Experiments with Low Power", "ch_workshop.html#ch_workshop_low_power", [
        [ "LAB #2", "ch_workshop.html#ch_workshop_lab2", null ],
        [ "Part 1 - Measure Proximity Sensor Low Power current", "ch_workshop.html#ch_workshop_lab2_part1", null ],
        [ "Part 2 - Effects of Sensor Sensitivity on Low Power current", "ch_workshop.html#ch_workshop_lab2_part2", null ],
        [ "Part 3 - Effects of Sensor Scan Rate on Low Power current", "ch_workshop.html#ch_workshop_lab2_part3", null ]
      ] ],
      [ "Exploring the CapTIvate™ Touch Library", "ch_workshop.html#ch_workshop_library", [
        [ "LAB #3", "ch_workshop.html#ch_workshop_lab3", null ],
        [ "Part 1 - CapTIvate™ Touch Library Overview", "ch_workshop.html#ch_workshop_lab3_part1", null ],
        [ "Part 2  - Explore CCS project structure and details", "ch_workshop.html#ch_workshop_lab3_part2", null ],
        [ "Part 3 - Creating and using callbacks", "ch_workshop.html#ch_workshop_lab3_part3", null ],
        [ "Part 4 - Determining sensor state and position", "ch_workshop.html#ch_workshop_lab3_part4", null ]
      ] ]
    ] ],
    [ "FAQ", "ch_FAQ.html", [
      [ "Design Kit", "ch_FAQ.html#ch_FAQ_DEVKIT", [
        [ "Does the kit arrive pre-programmed?", "ch_FAQ.html#ch_FAQ_DEVK00", null ],
        [ "How do I verify that the EVM is working?", "ch_FAQ.html#ch_FAQ_DEVK01", null ],
        [ "How can I increase the sensitivity or range of the proximity sensor in the out-of-box experience demo?", "ch_FAQ.html#ch_FAQ_DEVK02", null ]
      ] ],
      [ "CapTIvate™ Technology Design Center", "ch_FAQ.html#ch_FAQ_CDC", [
        [ "Can I download code from the Design Center?", "ch_FAQ.html#ch_FAQ_CDC00", null ],
        [ "What does the 'No connected HID devices' pop-up window mean?", "ch_FAQ.html#ch_FAQ_CDC01", null ],
        [ "Why is the target data display slow?", "ch_FAQ.html#ch_FAQ_CDC02", null ],
        [ "When do I need to generate a project from the design center and load onto the target?", "ch_FAQ.html#ch_FAQ_CDC03", null ],
        [ "What does updating a project from the design center do?", "ch_FAQ.html#ch_FAQ_CDC04", null ],
        [ "Where can I find the example demo project source code files?", "ch_FAQ.html#ch_FAZ_CDC05", null ],
        [ "Why is the CapTIvate™ Design Center window not visible when I launch the GUI?", "ch_FAQ.html#ch_FAQ_CDC06", null ]
      ] ],
      [ "CapTIvate™ Technology", "ch_FAQ.html#ch_FAQ_TECH", [
        [ "Why does sensitivity decrease as I increase the Conversion Gain?", "ch_FAQ.html#ch_FAQ_TECH00", null ],
        [ "Why is the scan rate slower than I specify?", "ch_FAQ.html#ch_FAQ_TECH01", null ]
      ] ]
    ] ],
    [ "Glossary", "ch_Glossary.html", [
      [ "Automatic Power Down", "ch_Glossary.html#ch_glossary_auto_power_down", null ],
      [ "Wake On Proximity Mode", "ch_Glossary.html#ch_glossary_system_wakeonprox_mode", null ],
      [ "Bias Current", "ch_Glossary.html#ch_glossary_bias_current", null ],
      [ "Button Group Sensor", "ch_Glossary.html#ch_glossary_button_group_sensor", null ],
      [ "Target Communications Configuration", "ch_Glossary.html#ch_glossary_communications", null ],
      [ "Channel", "ch_Glossary.html#ch_glossary_channel", null ],
      [ "Conversion Count", "ch_Glossary.html#ch_glossary_conversion_count", null ],
      [ "Conversion Gain", "ch_Glossary.html#ch_glossary_conversion_gain", null ],
      [ "Count", "ch_Glossary.html#ch_glossary_count", null ],
      [ "Count Filter", "ch_Glossary.html#ch_glossary_count_filter", null ],
      [ "Debounce", "ch_Glossary.html#ch_glossary_debounce", null ],
      [ "Delta", "ch_Glossary.html#ch_glossary_delta", null ],
      [ "Desired Resolution", "ch_Glossary.html#ch_glossary_desired_resolution", null ],
      [ "Electrode", "ch_Glossary.html#ch_glossary_electrode", null ],
      [ "Element", "ch_Glossary.html#ch_glossary_element", null ],
      [ "Engineering Parameters", "ch_Glossary.html#ch_glossary_engineering_parameters", null ],
      [ "Error Threshold", "ch_Glossary.html#ch_glossary_error_threshold", null ],
      [ "Frequency Divider", "ch_Glossary.html#ch_glossary_frequency_divider", null ],
      [ "Idle State", "ch_Glossary.html#ch_glossary_idle_state", null ],
      [ "LTA Filter", "ch_Glossary.html#ch_glossary_lta_filter", null ],
      [ "Modulation Enable", "ch_Glossary.html#ch_glossary_modulation_enable", null ],
      [ "Mutual Capacitance", "ch_Glossary.html#ch_glossary_mutual_capacitance", null ],
      [ "Negative Touch Threshold", "ch_Glossary.html#ch_glossary_negative_touch_threshold", null ],
      [ "Noise Immunity", "ch_Glossary.html#ch_glossary_noise_immunity", null ],
      [ "Parallel Sense Block", "ch_Glossary.html#ch_glossary_parallel_block", null ],
      [ "Phase Lengths", "ch_Glossary.html#ch_glossary_phase_lengths", null ],
      [ "Position Filter", "ch_Glossary.html#ch_glossaray_position_filter", null ],
      [ "Proximity Sensor", "ch_Glossary.html#ch_glossary_proximity_sensor", null ],
      [ "Proximity Threshold", "ch_Glossary.html#ch_glossary_prox_threshold", null ],
      [ "Run Time Recalibration", "ch_Glossary.html#ch_glossary_runtime_reCalibration", null ],
      [ "Sample Capacitor Discharge", "ch_Glossary.html#ch_glossary_sample_capacitor_discharge", null ],
      [ "Self Capacitance", "ch_Glossary.html#ch_glossary_self_capacitance", null ],
      [ "Sensor Port", "ch_Glossary.html#ch_glossary_sensor_port", null ],
      [ "Sensor Timeout Threshold", "ch_Glossary.html#ch_glossary_sensor_timeout_threshold", null ],
      [ "Slider Sensor", "ch_Glossary.html#ch_glossary_slider_sensor", null ],
      [ "Slider Trim", "ch_Glossary.html#ch_glossary_slider_trim", null ],
      [ "Sync Parameters", "ch_Glossary.html#ch_glossary_sync_parameters", null ],
      [ "System Report Rate", "ch_Glossary.html#ch_glossary_system_report_rate", null ],
      [ "Time Cycle", "ch_Glossary.html#ch_glossary_time_cycle", null ],
      [ "Time Estimation", "ch_Glossary.html#ch_glossary_time_estimation", null ],
      [ "Touch Threshold", "ch_Glossary.html#ch_glossary_touch_threshold", null ],
      [ "Trace", "ch_Glossary.html#ch_glossary_trace", null ],
      [ "Wake On Touch", "ch_Glossary.html#ch_glossary_wake_on_touch", null ],
      [ "Wheel Sensor", "ch_Glossary.html#ch_glossary_wheel_sensor", null ]
    ] ],
    [ "Disclaimer", "disclaimer.html", null ]
  ] ]
];

var NAVTREEINDEX =
[
"DesignCenter.html",
"ch_evm.html#ch_evm_get_started"
];

var SYNCONMSG = 'click to disable panel synchronisation';
var SYNCOFFMSG = 'click to enable panel synchronisation';