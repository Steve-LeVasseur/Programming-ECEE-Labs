%Main file
%Runs all code to calculate orbital maneauvers
function main()
%Gravitational Constant
G = 0.0000000000667408;

%Get starting conditions for calculations
userInputs = GetUserInput(); %function call
primary = userInputs{1}; %Name of the body the craft starts in orbit of
initial_periapsis_radius = userInputs{2}; %periapsis radius of starting orbit
initial_apoapsis_radius = userInputs{3}; %apoapsis radius of starting orbit
target = userInputs{4}; %Name of the body the craft will end up orbiting
target_periapsis_radius = userInputs{5}; %desired periapsis radius of final orbit
target_apoapsis_radius = userInputs{6}; %desired apoapsis radius of final orbit

% primary = app.StartingBodyDropDown.Value;
% initial_periapsis_radius = app.StartingPeriapsismEditField.Value;
% initial_apoapsis_radius = app.StartingApoapsismEditField.Value;
% target = app.DesiredBodyDropDown.Value;
% target_periapsis_radius = app.DesiredPeriapsismEditField.Value;
% target_apoapsis_radius = app.DesiredApoapsismEditField.Value;

%Get parameters of scenario based on primary and target bodies
parameters = getStartStopParameters(primary, target); %function call
mass_of_primary = parameters{1}; %Mass of the body the craft is initially orbiting
mass_of_target = parameters{2}; %Mass of the body the craft will end up orbiting
velocity_of_primary = parameters{3}; %Orbital velocity of the starting body, used for escape calculations
velocity_of_target = parameters{4}; %Orbitial velocity of the target body, used for capture calculations
start_SOI = parameters{5}; %Sphere of influence of initial primary, used to patch conics
end_SOI = parameters{6}; %Sphere of influence of target primary, used to patch conics
mean_distance_primary = parameters{7}; %Semimajor axis of the orbit about the sun of the initial primary
mean_distance_target = parameters{8}; %Semimajor axis of the orbit about the sun of the target primary
maneuver_type = ManuveurType(primary, target); %what kind of maneuver will be performed, 
                                               %returns either Adjustment, Escape, Rendezvous, or Transfer 
fprintf('%s\n', maneuver_type);


if strcmp(maneuver_type, "Adjustment")
    adjustment_burns = Adjustment(initial_periapsis_radius, initial_apoapsis_radius, target_periapsis_radius,...
                                    target_apoapsis_radius, mass_of_primary)
elseif strcmp(maneuver_type, "Rendezvous")
    capture_angle = 45; %Angle from the line connecting the sun to the target to the intersection of the craft's orbit and the SOI
    rendezvous_burns = Rendezvous(G, mass_of_primary, mass_of_target, mean_distance_target, velocity_of_target,...
            initial_periapsis_radius, initial_apoapsis_radius, capture_angle, end_SOI, target_periapsis_radius, target_apoapsis_radius)
        
elseif strcmp(maneuver_type, "Escape")
    escape_angle = 0; %Angle between vectors of primary velocity and spacecraft's exit velocity
    escape_burns = Escape(G, mass_of_primary, mass_of_target, mean_distance_primary, velocity_of_primary,...
            initial_periapsis_radius, initial_apoapsis_radius, escape_angle, start_SOI, target_periapsis_radius, target_apoapsis_radius)
end

end